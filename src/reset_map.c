/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** reset map
*/

#include "my.h"
#include "sokoban.h"

void reset_map(game_t *game)
{
    clear();
    for (int i = 0; i < game->y; ++i)
        free(game->map[i]);
    free(game->map);
    game->map = fill_tab(game->buffer);
    player_coords(game);
    display_map(game);
}