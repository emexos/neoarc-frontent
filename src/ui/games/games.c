#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "games.h"

// for now its an array
// but games are probably in ~/.config/neoarc/games/...
// and this file just reads every file/folder from the games folder and searches for binarys or smth
fc_game_t GAMES[] = {
    { "minecraft ", " by mojang" },
    { "doom ", " by id software" },
    { "celeste ", "platformar"},
    { "hollow knight ", "cool game :)" },
    { "stardew valley ", " "},
};
int GAMES_COUNT = 5;
int GAMES_SELECTED = 0;
int FILTERED[64];
int FILTERED_COUNT = 0;

void games_filter(const char *query) {
    FILTERED_COUNT = 0;
    int qlen = (int)strlen(query);

    for (int i = 0; i < GAMES_COUNT; i++) {
        if (qlen == 0) {
            FILTERED[FILTERED_COUNT++] = i;
            continue;
        }
        const char *name = GAMES[i].name;
        int nlen = (int)strlen(name);
        for (int j = 0; j <= nlen - qlen; j++) {
            bool match = true;
            for (int k = 0; k < qlen; k++) {
                if (tolower((unsigned char)name[j+k]) != tolower((unsigned char)query[k])) {
                    match = false;
                    break;
                }
            }
            if (match) {
                FILTERED[FILTERED_COUNT++] = i;
                break;
            }
        }
    }

    if (FILTERED_COUNT > 0) GAMES_SELECTED = FILTERED[0];
}
