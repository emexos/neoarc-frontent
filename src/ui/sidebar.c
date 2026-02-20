#include "../gen/gen.h"

void create_sidebar(void) {
    main_box = fc_box(dom, 0, 0, W, H);
    fc_box_border(main_box, FC_BORDER_DOUBLE);
    fc_box_colors(main_box, FC_GRAY, FC_DEFAULT);

    fc_node_t *sidebar = fc_box(dom, 1, 1, SIDEBAR_W, H - 2);
    fc_box_title(sidebar, " your games ");
    fc_box_title_align(sidebar, FC_ALIGN_CENTER);
    fc_box_border(sidebar, FC_BORDER_ROUNDED);
    fc_box_colors(sidebar, FC_CYAN, FC_DEFAULT);
    fc_box_title_color(sidebar, FC_BRIGHT_RED);
    fc_node_attach(main_box, sidebar);

    fc_node_t *game1 = fc_text(dom, 3, 3, SIDEBAR_W - 4, 1);
    fc_text_set(game1, "game 1");
    fc_text_colors(game1, FC_WHITE, FC_DEFAULT);
    fc_node_attach(sidebar, game1);

    fc_node_t *game2 = fc_text(dom, 3, 4, SIDEBAR_W - 4, 1);
    fc_text_set(game2, "game 2");
    fc_text_colors(game2, FC_WHITE, FC_DEFAULT);
    fc_node_attach(sidebar, game2);
    /*
    screen_sidebar_context: {
        info_box = fc_box(dom, 2, 2, 35, 8);
        fc_box_title(info_box, "game 1 ");
        fc_box_border(info_box, FC_BORDER_ROUNDED);
        fc_box_colors(info_box, FC_YELLOW, FC_DEFAULT);
        fc_node_attach(main_box, info_box);

        info_txt = fc_text(dom, 4, 4, 31, 4);
        fc_text_set(info_txt, "game 2");
        fc_text_colors(info_txt, FC_WHITE, FC_DEFAULT);
        fc_node_attach(info_box, info_txt);
    };*/
}
