#include "../tty.h"
#include "../io.h"
#include "../kbd.h"
#include "../../libc/include/string.h"
#include "apps.h"
#include "../../libc/include/error.h"
#include <stddef.h>

void error_1(void) {
    terminal_set_color(COLOR_LIGHT_RED, COLOR_BLACK);
    puts("-Error 1: Not a valid command. Type 'help' for commands-");
    check_color();
}

void error_2(void) {
    terminal_set_color(COLOR_LIGHT_RED, COLOR_BLACK);
    puts("-Error 2: Not Implemented-");
    check_color();
}

void error_3(void) {
    terminal_set_color(COLOR_LIGHT_RED, COLOR_BLACK);
    puts("-Error 3: Missing or insufficient arguements-");
    check_color();
}

void error_4(void) {
    terminal_set_color(COLOR_LIGHT_RED, COLOR_BLACK);
    puts("-Error 4: WarblerOS can currently only shut down on Virtual Machines. You need to do it manually-");
    check_color();
}

void error_6(void) {
    terminal_set_color(COLOR_LIGHT_RED, COLOR_BLACK);
    puts("-Error 6: Unspecified file name-");
    check_color();
}

void error_7(void) {
    terminal_set_color(COLOR_LIGHT_RED, COLOR_BLACK);
    puts("-Error 7: The requested command has been disabled-");
    check_color();
}

void error_8(void) {
    terminal_set_color(COLOR_LIGHT_RED, COLOR_BLACK);
    puts("-Error 8: The requested command has been moved to settings-");
    check_color();
}

void error_9(void) {
    terminal_set_color(COLOR_LIGHT_RED, COLOR_BLACK);
    puts("-Error 9: Division by zero-");
    check_color();
}

void error_10(void) {
    terminal_set_color(COLOR_LIGHT_RED, COLOR_BLACK);
    puts("-Error 10: Kernel Oops, Overflow-");
    check_color();
}

void error_11(void) {
    terminal_set_color(COLOR_LIGHT_RED, COLOR_BLACK);
    puts("-Error 11: Kernel Oops, Non-possible else statement-");
    check_color();
}

void application_err_1(void) {
    terminal_set_color(COLOR_LIGHT_RED, COLOR_BLACK);
    puts("-Your application has ran into a problem and closed-");
    puts("-Application Error 1: The app you are in has forced an exit-");
    check_color();    
}