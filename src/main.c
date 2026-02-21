#include "gen/gen.h"
#include "ui/uiinclude.h"

int main(void) {
    initfcscreen();
    fc_mouse_enable(true);

    create_mainscreen();
    create_sidebar();
    create_gameinfoscreen();
    fc_dom_render(dom);

    fc_event_t ev;
    while (1) {
        if (!fc_input_read(&ev, 50)) continue;

        if (ev.type == FC_EV_KEY) {
            if (ev.key == FC_KEY_ESC) {
                if (sidebar_is_searching()) {
                    fc_dom_click(dom, 3, 3);
                } else {
                    break;
                }
            }

            if (sidebar_is_searching()) {
                sidebar_handle_key(ev.key, ev.ch);
            } else {
                if (ev.key == 'q') break;
                if (ev.key == FC_KEY_UP   || ev.key == 'k') {
                    sidebar_select(GAMES_SELECTED - 1);
                    mainscreen_update();
                }
                if (ev.key == FC_KEY_DOWN || ev.key == 'j') {
                    sidebar_select(GAMES_SELECTED + 1);
                    mainscreen_update();
                }
            }
        }

        if (ev.type == FC_EV_MOUSE_PRESS && ev.btn == 1) {
            fc_dom_click(dom, ev.x, ev.y);
            mainscreen_update();
        }

        if (ev.type == FC_EV_MOUSE_PRESS || ev.type == FC_EV_MOUSE_RELEASE) {
            fc_dom_hover(dom, ev.x, ev.y);
        }

        fc_dom_render(dom);
    }

    fc_mouse_enable(false);
    stopfcscreen();
    return 0;
}
