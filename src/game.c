/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** game part
*/

#include "my.h"
#include "sokoban.h"

void reset_map(game_t *game)
{
    erase();
    game->map = fill_tab(game->buffer);
    player_coords(game);
    display_map(game);
}

void win_check(game_t *game)
{
    int count = 0;

    for (int i = 0; i < game->nb_o; ++i) {
        if (game->map[game->o_coords[i][0]][game->o_coords[i][1]] == 'X')
            count += 1;
    }
    if (count == game->nb_o) {
        erase();
        endwin();
        for (int i = 0; i < game->y; ++i)
            free(game->map[i]);
        free(game->map);
        free(game->buffer);
        for (int i = 0; i < game->nb_o; ++i)
            free(game->o_coords[i]);
        free(game->o_coords);
        exit(0);
    }
}

void game_fun(game_t *game)
{
    initscr();
    display_map(game);
    keypad(stdscr, TRUE);
    while (1) {
        game->key = getch();
        key_detection(game);
        erase();
        display_map(game);
        win_check(game);
    }
}