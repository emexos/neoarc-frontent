#include "../gen/gen.h"

void create_sidebar(void){
    main_box = fc_box(dom, 0, 0, W, H);
    fc_box_title(main_box, " your games: ");
    fc_box_title_align(main_box, FC_ALIGN_CENTER); // otherwise its rightbinded
    fc_box_border(main_box, FC_BORDER_DOUBLE);
    fc_box_colors(main_box, FC_CYAN, FC_DEFAULT);
    fc_box_title_color(main_box, FC_BRIGHT_RED);

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
