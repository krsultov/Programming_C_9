#include <stdio.h>

#define COMMAND(NAME, TYPE) TYPE##_##NAME##_command
#define DEFINE_COMMAND(NAME, TYPE) void COMMAND(NAME, TYPE)(void)

DEFINE_COMMAND(quit, internal) {
    printf("internal quit command\n");
}

DEFINE_COMMAND(test, test) {
    printf("test test command\n");
}

int main(void) {
    internal_quit_command();
    test_test_command();

    return 0;
}