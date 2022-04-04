#include "./lib/io/io.h"
#include "./lib/windows/main.c"

void kernel_main() {
    print_clear();
    test_input();
    Window* win1 = Window_new(10, 10, 300, 200, &context);
    Window* win2 = Window_new(100, 150, 400, 400, &context);
    Window* win3 = Window_new(200, 100, 200, 600, &context);

    //And draw them
    Window_paint(win1);
    Window_paint(win2);
    Window_paint(win3);    

}