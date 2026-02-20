#include "../gen/gen.h"

void init_dom() {
    dom = fc_dom_new();
    W = dom->w;
    H = dom->h;
}
