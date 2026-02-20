#include "gen/gen.h"
#include "ui/uiinclude.h"

int main(void) {
    initfcscreen();

    screen_main: {
        create_sidebar();
        create_mainscreen();
        create_gameinfoscreen();
    };

    fc_dom_render(dom);

    unsigned char c;
    while (read(STDIN_FILENO, &c, 1) > 0) { // why tf doesnt getcahr work... :(
        if (c == 'q' || c == 'Q' || c == 3) break;
    }


    stopfcscreen();

    return 0;
}
