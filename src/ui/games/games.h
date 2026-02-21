#pragma once

typedef struct {
    const char *name;
    const char *description;
} fc_game_t;

extern fc_game_t GAMES[];
extern int GAMES_COUNT;
extern int GAMES_SELECTED;
extern int FILTERED[];
extern int FILTERED_COUNT;

void games_filter(const char *query);
