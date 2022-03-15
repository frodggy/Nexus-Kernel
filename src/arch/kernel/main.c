#include "./lib/print.c"

void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_BLUE, PRINT_COLOR_BLACK);
    print_str("Welcome to Core os powered by the Nexus kernel\n");
    print_str("Press [ENTER] to continue");
}