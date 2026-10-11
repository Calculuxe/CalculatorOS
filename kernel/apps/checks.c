#include "../tty.h"
#include "../io.h"
#include "../kbd.h"
#include "../../libc/include/string.h"
#include "apps.h"
#include "../../libc/include/error.h"
#include <stddef.h>

int colorindicator = 13;

void check_color(void) {
    if (colorindicator == 1) {
            terminal_set_color(COLOR_BLUE, COLOR_BLACK);
    } else if (colorindicator == 2) {
            terminal_set_color(COLOR_LIGHT_BLUE, COLOR_BLACK);
    } else if (colorindicator == 3) {
            terminal_set_color(COLOR_GREEN, COLOR_BLACK);
    } else if (colorindicator == 4) {
            terminal_set_color(COLOR_LIGHT_GREEN, COLOR_BLACK);
    } else if (colorindicator == 5) {
            terminal_set_color(COLOR_RED, COLOR_BLACK);
    } else if (colorindicator == 6) {
            terminal_set_color(COLOR_LIGHT_RED, COLOR_BLACK);
    } else if (colorindicator == 7) {
            terminal_set_color(COLOR_LIGHT_BROWN, COLOR_BLACK);
    } else if (colorindicator == 8) {
            terminal_set_color(COLOR_MAGENTA, COLOR_BLACK);
    } else if (colorindicator == 9) {
            terminal_set_color(COLOR_LIGHT_MAGENTA, COLOR_BLACK);
    } else if (colorindicator == 10) {
            terminal_set_color(COLOR_CYAN, COLOR_BLACK);
    } else if (colorindicator == 11) {
            terminal_set_color(COLOR_LIGHT_CYAN, COLOR_BLACK);
    } else if (colorindicator == 12) {
            terminal_set_color(COLOR_BROWN, COLOR_BLACK);
    } else if (colorindicator == 13) {
            terminal_set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
    } else if (colorindicator == 14) {
            terminal_set_color(COLOR_DARK_GREY, COLOR_BLACK);
    } else if (colorindicator == 15) {
            terminal_set_color(COLOR_WHITE, COLOR_BLACK);
        }
}