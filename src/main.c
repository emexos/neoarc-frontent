#include "gen/gen.h"
#include "ui/uiinclude.h"

int main(void) {
    initfcscreen();

    create_sidebar();
    create_mainscreen();

    screen_main: {
        // main page/ information about an app/game
    };

    fc_dom_render(dom);

    sleep(5);

    stopfcscreen();

    return 0;
}
