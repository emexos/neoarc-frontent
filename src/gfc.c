#include "gen/gen.h"

void initfcscreen() {
    dom = fc_dom_new();
    W = dom->w;
    H = dom->h;
    fc_term_init();
    fc_term_altscreen(true);
    fc_term_cursor(false);
}

void stopfcscreen() {
    fc_term_cursor(true); // otherwise you dont have a cursor :(
    fc_term_altscreen(false);
    fc_term_flush();
    fc_term_shutdown();
    fc_dom_free(dom);
}
