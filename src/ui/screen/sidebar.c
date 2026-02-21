#include <string.h>
#include <stdio.h>
#include "../../gen/gen.h"
#include "../games/games.h"

static fc_node_t *game_buttons[64];
static fc_node_t *search_btn = NULL;
static bool searching = false;
static char search_query[128];
static fc_node_t *sidebar_ref = NULL;

void sidebar_select(int idx);
static void rebuild_buttons(void);

bool sidebar_is_searching(void) { return searching; }

static void on_search_click(fc_node_t *n)
{
    (void)n;
    searching = !searching;
    if (!searching) {
        memset(search_query, 0, sizeof(search_query));
        games_filter("");
        fc_button_colors(search_btn, FC_WHITE, FC_DEFAULT);
        fc_button_set_label(search_btn, "search games");
    } else {
        fc_button_colors(search_btn, FC_BLACK, FC_C256(214));
        fc_button_set_label(search_btn, "|");
    }
    fc_button_hover_colors(search_btn, FC_BLACK, FC_C256(214));
    rebuild_buttons();
}

static void on_game_click(fc_node_t *n) {
    int local = (int)(long)fc_button_get_userdata(n);
    if (local < FILTERED_COUNT) {
        GAMES_SELECTED = FILTERED[local];
        sidebar_select(GAMES_SELECTED);
    }
}

static void rebuild_buttons(void)
{
    for (int i = 0; i < GAMES_COUNT; i++) {
        game_buttons[i]->hidden = true;
        fc_node_dirty(game_buttons[i]);
    }
    for (int i = 0; i < FILTERED_COUNT; i++) {
        int gi = FILTERED[i];
        fc_node_t *btn = game_buttons[gi];
        btn->hidden = false;
        btn->y = 5 + i;
        fc_button_set_userdata(btn, (void *)(long)i);
        fc_node_dirty(btn);
    }
}

void sidebar_select(int idx)
{
    if (idx < 0)            idx = 0;
    if (idx >= GAMES_COUNT) idx = GAMES_COUNT - 1;
    GAMES_SELECTED = idx;

    for (int i = 0; i < GAMES_COUNT; i++) {
        bool sel = (i == GAMES_SELECTED);
        fc_button_colors(game_buttons[i],
            sel ? FC_BLACK : FC_WHITE,
            sel ? FC_CYAN  : FC_DEFAULT);
    }
}

void sidebar_handle_key(int key, char ch) {
    if (!searching) return;
    char display[128];

    int qlen = (int)strlen(search_query);

    if (key == FC_KEY_BACKSPACE) {
        if (qlen > 0) search_query[qlen - 1] = 0;
    } else if (ch >= 32 && ch < 127 && qlen < 64) {
        search_query[qlen] = ch;
        search_query[qlen + 1] = 0;
    } else {
        return;
    }
    if (strlen(search_query) == 0) {
        snprintf(display, sizeof(display), "|");
    } else {
        snprintf(display, sizeof(display), "%s|", search_query);
    }
    fc_button_set_label(search_btn, display);

    games_filter(search_query);
    rebuild_buttons();
}

void create_sidebar(void) {
    sidebar_ref = fc_box(dom, 1, 1, SIDEBAR_W, H - 2);
    fc_box_title(sidebar_ref,  SIDEBARREF_TITLE);
    fc_box_title_align(sidebar_ref, SIDEBARREF_IS_ALIGN);
    fc_box_border(sidebar_ref, SIDEBARREF_BORDER_DESIGN);
    fc_box_colors(sidebar_ref, FC_CYAN, FC_DEFAULT);
    fc_box_title_color(sidebar_ref, FC_BRIGHT_RED);
    fc_node_attach(main_box, sidebar_ref);

    search_btn = fc_button(dom, 3, 3, SIDEBAR_W - 4, SEARCHBTN_TEXT);
    fc_button_colors(search_btn, FC_WHITE, FC_DEFAULT);
    fc_button_hover_colors(search_btn, FC_BLACK, FC_C256(214));
    fc_button_on_click(search_btn, on_search_click);
    fc_node_attach(sidebar_ref, search_btn);

    games_filter("");
    for (int i = 0; i < GAMES_COUNT; i++) {
        fc_node_t *btn = fc_button(dom, 3, 5 + i, SIDEBAR_W - 4, GAMES[i].name);
        fc_button_colors(btn, FC_WHITE, FC_DEFAULT);
        fc_button_hover_colors(btn, FC_BLACK, FC_CYAN);
        fc_button_on_click(btn, on_game_click);
        fc_button_set_userdata(btn, (void *)(long)i);
        fc_node_attach(sidebar_ref, btn);
        game_buttons[i] = btn;
    }

    sidebar_select(0);
}
