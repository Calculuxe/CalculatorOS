#include "../tty.h"
#include "../io.h"
#include "../kbd.h"
#include "../../libc/include/string.h"
#include "apps.h"
#include "../../libc/include/error.h"
#include <stddef.h>

extern uint8_t shift;
extern char user[128];
extern size_t VGA_WIDTH;
extern size_t VGA_HEIGHT;
extern int colorindicator;

void print_color_options(void) {
    puts("--Choose a text color by typing: 'color text' and then the color of choice--");
    terminal_set_color(COLOR_BLUE, COLOR_BLACK);
    puts("-blue-");
    terminal_set_color(COLOR_LIGHT_BLUE, COLOR_BLACK);
    puts("-light blue-");
    terminal_set_color(COLOR_GREEN, COLOR_BLACK);
    puts("-green-");
    terminal_set_color(COLOR_LIGHT_GREEN, COLOR_BLACK);
    puts("-light green-");
    terminal_set_color(COLOR_RED, COLOR_BLACK);
    puts("-red-");
    terminal_set_color(COLOR_LIGHT_RED, COLOR_BLACK);
    puts("-light red-");
    terminal_set_color(COLOR_LIGHT_BROWN, COLOR_BLACK);
    puts("-yellow-");
    terminal_set_color(COLOR_MAGENTA, COLOR_BLACK);
    puts("-magenta-");
    terminal_set_color(COLOR_LIGHT_MAGENTA, COLOR_BLACK);
    puts("-light magenta-");
    terminal_set_color(COLOR_CYAN, COLOR_BLACK);
    puts("-cyan-");
    terminal_set_color(COLOR_LIGHT_CYAN, COLOR_BLACK);
    puts("-light cyan-");
    terminal_set_color(COLOR_BROWN, COLOR_BLACK);
    puts("-brown-");
    terminal_set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
    puts("-light grey-");
    terminal_set_color(COLOR_DARK_GREY, COLOR_BLACK);
    puts("-dark grey-");
    terminal_set_color(COLOR_WHITE, COLOR_BLACK);
    puts("-white-");
    terminal_set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
}

void print_bg_options(void) {
    terminal_set_color(COLOR_BLUE, COLOR_BLACK);
    puts("-blue-");
    terminal_set_color(COLOR_LIGHT_BLUE, COLOR_BLACK);
    puts("-light blue-");
    terminal_set_color(COLOR_GREEN, COLOR_BLACK);
    puts("-green-");
    terminal_set_color(COLOR_LIGHT_GREEN, COLOR_BLACK);
    puts("-light green-");
    terminal_set_color(COLOR_RED, COLOR_BLACK);
    puts("-red-");
    terminal_set_color(COLOR_LIGHT_RED, COLOR_BLACK);
    puts("-light red-");
    terminal_set_color(COLOR_LIGHT_BROWN, COLOR_BLACK);
    puts("-yellow-");
    terminal_set_color(COLOR_MAGENTA, COLOR_BLACK);
    puts("-magenta-");
    terminal_set_color(COLOR_LIGHT_MAGENTA, COLOR_BLACK);
    puts("-light magenta-");
    terminal_set_color(COLOR_CYAN, COLOR_BLACK);
    puts("-cyan-");
    terminal_set_color(COLOR_LIGHT_CYAN, COLOR_BLACK);
    puts("-light cyan-");
    terminal_set_color(COLOR_BROWN, COLOR_BLACK);
    puts("-brown-");
    terminal_set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
    puts("-light grey-");
    terminal_set_color(COLOR_DARK_GREY, COLOR_BLACK);
    puts("-dark grey-");
    terminal_set_color(COLOR_WHITE, COLOR_BLACK);
    puts("-white-");
    terminal_set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
}

int settings(void) {
	char buff[128] = {0};
    memset(buff, 0, sizeof(buff));
	settings_printprompt();
	while (1) {
		uint8_t byte;
		while (byte = scan()) {
			if (byte == 0x1c) {
				if (strlen(buff) > 0 && strcmp(buff, "return") == 0) {
					main();
                } else if (strlen(buff) > 0 && strcmp(buff, "help") == 0) {
                    puts("--Commands--");
                    puts("-return: Return to the main menu-");
                    puts("-color text {color}: change the text color-");
                    puts("-color bg {color}: change the background color-");
                    puts("-clear: clear the screen-");
                } else if (strlen(buff) > 0 && strcmp(buff, "color text") == 0) {
                    terminal_initialize();
                    print_color_options();
                } else if (strlen(buff) > 0 && strcmp(buff, "color text blue") == 0) {
                    terminal_set_color(COLOR_BLUE, COLOR_BLACK);
                    colorindicator = 1;
                } else if (strlen(buff) > 0 && strcmp(buff, "color text light blue") == 0) {
                    terminal_set_color(COLOR_LIGHT_BLUE, COLOR_BLACK);
                    colorindicator = 2;
                } else if (strlen(buff) > 0 && strcmp(buff, "color text green") == 0) {
                    terminal_set_color(COLOR_GREEN, COLOR_BLACK);
                    colorindicator = 3;
                } else if (strlen(buff) > 0 && strcmp(buff, "color text light green") == 0) {
                    terminal_set_color(COLOR_LIGHT_GREEN, COLOR_BLACK);  
                    colorindicator = 4;  
                } else if (strlen(buff) > 0 && strcmp(buff, "color text red") == 0) {
                    terminal_set_color(COLOR_RED, COLOR_BLACK);  
                    colorindicator = 5;  
                } else if (strlen(buff) > 0 && strcmp(buff, "color text light red") == 0) {
                    terminal_set_color(COLOR_LIGHT_RED, COLOR_BLACK);
                    colorindicator = 6;
                } else if (strlen(buff) > 0 && strcmp(buff, "color text yellow") == 0) {
                    terminal_set_color(COLOR_LIGHT_BROWN, COLOR_BLACK);
                    colorindicator = 7;
                } else if (strlen(buff) > 0 && strcmp(buff, "color text magenta") == 0) {
                    terminal_set_color(COLOR_MAGENTA, COLOR_BLACK);   
                    colorindicator = 8; 
                } else if (strlen(buff) > 0 && strcmp(buff, "color text light magenta") == 0) {
                    terminal_set_color(COLOR_LIGHT_MAGENTA, COLOR_BLACK);
                    colorindicator = 9;   
                } else if (strlen(buff) > 0 && strcmp(buff, "color text cyan") == 0) {
                    terminal_set_color(COLOR_CYAN, COLOR_BLACK);
                    colorindicator = 10;
                } else if (strlen(buff) > 0 && strcmp(buff, "color text light cyan") == 0) {
                    terminal_set_color(COLOR_LIGHT_CYAN, COLOR_BLACK);
                    colorindicator = 11;
                } else if (strlen(buff) > 0 && strcmp(buff, "color text brown") == 0) {
                    terminal_set_color(COLOR_BROWN, COLOR_BLACK);
                    colorindicator = 12;
                } else if (strlen(buff) > 0 && strcmp(buff, "color text light grey") == 0) {
                    terminal_set_color(COLOR_LIGHT_GREY, COLOR_BLACK);    
                    colorindicator = 13;    
                } else if (strlen(buff) > 0 && strcmp(buff, "color text dark grey") == 0) {
                    terminal_set_color(COLOR_DARK_GREY, COLOR_BLACK);     
                    colorindicator = 14;
                } else if (strlen(buff) > 0 && strcmp(buff, "color text white") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_BLACK);       
                    colorindicator = 15;
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg") == 0) {
                    terminal_initialize();
                    print_bg_options();
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg blue") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_BLUE);
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg light blue") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_LIGHT_BLUE);
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg green") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_GREEN);
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg light green") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_LIGHT_GREEN);    
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg red") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_RED);    
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg light red") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_LIGHT_RED);
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg yellow") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_LIGHT_BROWN);
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg magenta") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_MAGENTA);    
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg light magenta") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_LIGHT_MAGENTA);    
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg cyan") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_CYAN);
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg light cyan") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_LIGHT_CYAN);
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg brown") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_BROWN);
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg light grey") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_LIGHT_GREY);        
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg dark grey") == 0) {
                    terminal_set_color(COLOR_WHITE, COLOR_DARK_GREY);     
                } else if (strlen(buff) > 0 && strcmp(buff, "color bg white") == 0) {
                    terminal_set_color(COLOR_BLACK, COLOR_WHITE);
                } else {
                    error_1();
                }
				settings_printprompt();
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
                        settings_printprompt();
                    }
                    s = ctos(s, c);
                    printf("%s", s);
                    strcpy(&buff[strlen(buff)], s);
                }
            }
            move_cursor(get_terminal_row(), get_terminal_col());
        }
    }
    return 0;
}