#include "../tty.h"
#include "../io.h"
#include "../kbd.h"
#include "../../libc/include/string.h"
#include "apps.h"
#include "../../libc/include/error.h"
#include <stddef.h>

extern char b[7];

void help(void) {
puts("--Avaliable Operations--");
puts("-addition-");
puts("-subtraction-");
puts("-multiplication-");
puts("-division-");
puts("-clear-");
puts("-exit: Exit CalculatorOS-");
puts("-about: View info about WarblerOS-");
puts("-devlog: View the WarblerOS devlog-");
puts("-bugs: View the known bugs of this build-");
puts("-settings: Customize the text and background color-");
    
}

void devlog(void) {
    puts("--Devlog--");
    puts("-Nothing yet-");
}

void bugs(void) {
    printf("\n--Known Bugs For Build %s", b);
    printf("-");
    puts("-Arrow keys count as number keys-");
    puts("-WarblerOS will not shut down on real hardware or unsupported hypervisors-");
    puts("-If you overcrowd the screen too much, the cursor may get lost. If this happens, type the 'clear' command-");
}
void about(void) {
    puts("--About CalculatorOS--");
    printf("\n-CalculatorOS Chocolate Chip Build %s-", b);
    puts("-Created by Gavin Elias-");
    puts("-This is an alpha build, so it is not stable yet!-");
}