#include "kernel/tty.h"
#include "kernel/apps/apps.h"
#include "kernel/io.h"
#include "kernel/kbd.h"
#include "libc/include/string.h"
#include "kernel/apps/apps.h"
#include "libc/include/error.h"
#warning "This is an alpha build of WarblerOS. Bugs and instability may be found"

char b[7] = "2610.10";
extern uint8_t shift;
int num1;
int num2;
int num3;
int addition(void) {
    num3 = num1 + num2;
    printf("\n%d + %d is %d", num1, num2, num3);
    return 0;
}

int subtraction(void) {
    num3 = num1 - num2;
    printf("\n%d - %d is %d", num1, num2, num3);
    return 0;
}

int multiplication(void) {
    num3 = num1 * num2;
    printf("\n%d * %d is %d", num1, num2, num3);
    return 0;
}

int division(void) {
    if (num2 == 0) {
        error_9();
        return 0;
    }
    num3 = num1 / num2;
    printf("\n%d / %d is %d", num1, num2, num3);
    return 0;
}

int read_number(void) {
    int value = 0;
    size_t digits = 0;
    int negative = 0;
    uint8_t byte;

    while (1) {
        while ((byte = scan()) == 0) {
            /* tick. tock... ARE YOU TYPING YET?!!!*/
        }

        if (byte == 0x1c) {
            break;
        }

        char c = shift ? shiftmap[byte] : normalmap[byte];
        if (c == '\b') {
            if (digits > 0) {
                value /= 10;
                digits--;
                printf("\b");
            } else if (negative) {
                negative = 0;
                printf("\b");
            }
        } else if (c == '-' && digits == 0 && !negative) {
        negative = 1;
        printf("%c", c);
        } else if (c >= '0' && c <= '9') {
            value = value * 10 + (c - '0');
            digits++;
            printf("%c", c);
        }
        move_cursor(get_terminal_row(), get_terminal_col());
    }
    return negative ? -value : value;
}

void shutdown(void) {
    outw(0x604, 0x2000);
    outw(0x4004, 0x3400);
    outw(0x600, 0x34);
    error_4();
    terminal_initialize();
}

void kernel_early(void) {
    terminal_initialize();
    printf("---Welcome To CalculatorOS---");
    check_color();
}

int main(void) {
	char buff[128] = {0};
    memset(buff, 0, sizeof(buff));
    calc_printprompt();
	while (1) { 
		uint8_t byte;
		while (byte = scan()) {
			if (byte == 0x1c) {
				if (strlen(buff) > 0 && strcmp(buff, "exit") == 0){
					shutdown();
                    return 0;
                 } else if (strlen(buff) > 0 && strcmp(buff, "addition") == 0) {
					puts("Enter a number: ");
                    move_cursor(get_terminal_row(), get_terminal_col());
                    num1 = read_number();

                    printf("\nWhat do you want to add to %d: ", num1);
                    move_cursor(get_terminal_row(), get_terminal_col());
                    num2 = read_number();

                    addition();
                } else if (strlen(buff) > 0 && strcmp(buff, "subtraction") == 0) {
					puts("Enter a number: ");
                    move_cursor(get_terminal_row(), get_terminal_col());
                    num1 = read_number();

                    printf("\nWhat do you want to remove from %d: ", num1);
                    move_cursor(get_terminal_row(), get_terminal_col());
                    num2 = read_number();

                    subtraction();
                } else if (strlen(buff) > 0 && strcmp(buff, "multiplication") == 0) {
					puts("Enter a number: ");
                    move_cursor(get_terminal_row(), get_terminal_col());
                    num1 = read_number();

                    printf("\nWhat do you want to multiply %d by: ", num1);
                    move_cursor(get_terminal_row(), get_terminal_col());
                    num2 = read_number();

                    multiplication();
                } else if (strlen(buff) > 0 && strcmp(buff, "division") == 0) {
					puts("Enter a number: ");
                    move_cursor(get_terminal_row(), get_terminal_col());
                    num1 = read_number();

                    printf("\nWhat do you want to divide %d by: ", num1);
                    move_cursor(get_terminal_row(), get_terminal_col());
                    num2 = read_number();

                    division();
                } else if (strlen(buff) > 0 && strcmp(buff, "clear") == 0) {
                    terminal_initialize();
                } else if (strlen(buff) > 0 && strcmp(buff, "help") == 0) {
                    help();
                } else if (strlen(buff) > 0 && strcmp(buff, "bugs") == 0) {
                    bugs();
                } else if (strlen(buff) > 0 && strcmp(buff, "about") == 0) {
                    about();
                } else if (strlen(buff) > 0 && strcmp(buff, "settings") == 0) {
                    settings();
                } else if (strlen(buff) > 0 && strcmp(buff, "about") == 0) {
                    about();
                } else {
                	error_1();
                }
				calc_printprompt();
				memset(&buff[0], 0, sizeof(buff));
				break;
			} else {
                char c = shift ? shiftmap[byte] : normalmap[byte];
                if (c == '\b') {
                    size_t len = strlen(buff);
                    if (len > 0) {
                        buff[len - 1] = '\0';
                        printf("\b");
                    }
                } else {
                    char *s;
                    char s_storage[2];
                    s = s_storage;
                    size_t len = strlen(buff);
                    if (len >= sizeof(buff) - 1) {
                        memset(buff, 0, sizeof(buff));
                        len = 0;
                        error_10();
                        calc_printprompt();
                    }
                    s = ctos(s, c);
                    printf("%s", s);
                    strcpy(&buff[strlen(buff)], s);
                }
            }
            move_cursor(get_terminal_row(), get_terminal_col());
        }
    }
}
