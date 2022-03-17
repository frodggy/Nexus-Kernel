#include "./lib/io/input.h"
#include "./lib/io/char.c"
#include "./lib/io/print.c"

uint inb (uint16_t _port)
{
    uint rv;
    asm volatile("in %1, %0" : "=a" (rv): "dN" (_port));
    return rv;
}
void outb (uint16_t _port, uint _data)
{
    asm volatile("out %1, %0" : : "dN" (_port), "a" (_data));
}


char get_input_keycode()
{
  char ch = 0;
  while((ch = inb(KEYBOARD_PORT)) != 0){
    if(ch > 0)
      return ch;
  }
  return ch;
}

/*
keep the cpu busy for doing nothing(nop)
so that io port will not be processed by cpu
here timer can also be used, but lets do this in looping counter
*/
void wait_for_io(uint32_t timer_count)
{
  while(1){
    asm volatile("nop");
    timer_count--;
    if(timer_count <= 0)
      break;
    }
}

void sleep(uint32_t timer_count)
{
  wait_for_io(timer_count);
}

void test_input()
{
  char ch = 0;
  char keycode = 0;
  do{
    keycode = get_input_keycode();
    if(keycode == KEY_ENTER){
      print_newline();
    }else{
      ch = get_ascii_char(keycode);
      print_char(ch);
    }
    sleep(0x02FFFFFF);
  }while(ch > 0);
}


void kernel_main() {
    print_clear();
    test_input();
}