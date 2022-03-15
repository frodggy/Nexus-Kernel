#include "../io/input.o"
#include "../io/print.c"


namespace nxt::apps {
    void Terminal() {
        while (true) {
            nxt::io::print_str("iso@core \\> ");
        }
    }
}