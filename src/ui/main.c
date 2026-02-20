#include "../gen/gen.h"

void create_mainscreen(void) {
    int sidebar_end = 39;
    int main_w = W - sidebar_end - 1;

    fc_node_t *main_screen = fc_box(dom, sidebar_end, 2, main_w, H - 4);
    fc_box_title(main_screen, " main ");
    fc_box_border(main_screen, FC_BORDER_SINGLE);
    fc_box_colors(main_screen, FC_WHITE, FC_DEFAULT);
    fc_node_attach(main_box, main_screen);

    fc_node_t *content = fc_text(dom, sidebar_end + 2, 4, main_w - 4, H - 8);
    fc_text_set(content, "select a game on the left");
    fc_text_colors(content, FC_GRAY, FC_DEFAULT);
    fc_node_attach(main_screen, content);
}
