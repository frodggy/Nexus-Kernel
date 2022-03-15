#include "./lib/print.c"
#include "./lib/apps/terminal.c"


void kernel_main() {
    print_clear();
    nxt::apps::terminal()
}