#include "gen/gen.h"
#include "ui/uiinclude.h"

int main(void) {
    initfcscreen();

    create_sidebar();

    screen_main: {
        // main page/ information about an app/game
    }

    fc_dom_render(dom);
    stopfcscreen();

    return 0;
}
