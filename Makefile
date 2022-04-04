version = 0.0.1
code = vultr
name = Nexus
arch ?= x86_64
kernel := maked/vmnxtz-$(version)
iso := maked/$(name)-$(code)@$(version)-$(arch).iso

linker_script := src/arch/kernel/$(arch)/linker.ld
grub_cfg := src/arch/kernel/$(arch)/grub.cfg
assembly_source_files := $(wildcard src/arch/kernel/$(arch)/*.asm)
assembly_object_files := $(patsubst src/arch/kernel/$(arch)/%.asm, \
	maked/arch/$(arch)/%.o, $(assembly_source_files))

.PHONY: all clean run iso

all: $(kernel)

clean:
	@rm -r maked

run: $(iso)
	@qemu-system-x86_64 -cdrom $(iso)

iso: $(iso)

$(iso): $(kernel) $(grub_cfg)
	mkdir -p maked/isofiles/boot/grub
	cp $(kernel) maked/isofiles/boot/vmnxtz-$(version)
	cp $(grub_cfg) maked/isofiles/boot/grub
	grub-mkrescue -o $(iso) maked/isofiles > /dev/null
	rm -r maked/isofiles

$(kernel): $(assembly_object_files) $(linker_script)
	@ld -n -T $(linker_script) -o $(kernel) $(assembly_object_files) maked/arch/x86_64/main.o

# compile assembly files
maked/arch/$(arch)/%.o: src/arch/kernel/$(arch)/%.asm
	@mkdir -p $(shell dirname $@)
	@gcc src/arch/kernel/main.c -Wall -march=x86-64 -ffreestanding -c -nostartfiles -Wimplicit-function-declaration -o maked/arch/x86_64/main.o
	@nasm -felf64 $< -o $@