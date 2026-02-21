#include "../../gen/gen.h"
#include "../games/games.h"

static fc_node_t *main_content = NULL;

void mainscreen_update(void) {
    if (!main_content) return;
    fc_text_set(main_content, GAMES[GAMES_SELECTED].description);
}

void create_mainscreen(void) {
    main_box = fc_box(dom, 0, 0, W, H);
    fc_box_border(main_box, FC_BORDER_DOUBLE);
    fc_box_colors(main_box, FC_GRAY, FC_DEFAULT);
}

void create_gameinfoscreen(void) {
    int mx = SIDEBAR_W + 2;
    int mw = W - mx - 1;

    fc_node_t *main_screen = fc_box(dom, mx, 1, mw, H - 2);
    fc_box_title(main_screen, " info ");
    fc_box_border(main_screen, FC_BORDER_SINGLE);
    fc_box_colors(main_screen, FC_WHITE, FC_DEFAULT);
    fc_node_attach(main_box, main_screen);

    main_content = fc_text(dom, mx + 2, 3, mw - 4, H - 6);
    fc_text_set(main_content, GAMES[0].description);
    fc_text_colors(main_content, FC_GRAY, FC_DEFAULT);
    fc_node_attach(main_screen, main_content);
}
