#include "../gen/gen.h"

static int mx;
static int mw;

void create_mainscreen(void) {
    mx = SIDEBAR_W + 2;
    mw = W - mx - 1;

    fc_node_t *main_screen = fc_box(dom, mx, 1, mw, H - 2);
    fc_box_title(main_screen, " main ");
    fc_box_border(main_screen, FC_BORDER_SINGLE);
    fc_box_colors(main_screen, FC_WHITE, FC_DEFAULT);
    fc_node_attach(main_box, main_screen);
}

void create_gameinfoscreen(void) {
    fc_node_t *content = fc_text(dom, mx + 2, 3, mw - 4, H - 6);
    fc_text_set(content, "select a game on the left");
    fc_text_colors(content, FC_GRAY, FC_DEFAULT);
    fc_node_attach(main_box, content);
}
