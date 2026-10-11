#include "io.h"
#include "tty.h"

void confirmation(void) {
    terminal_set_color(COLOR_LIGHT_GREEN, COLOR_BLACK);
    puts("It is now safe to turn off your computer-");
}