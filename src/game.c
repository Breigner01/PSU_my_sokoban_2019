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
    clear();
    for (int i = 0; i < game->y; ++i)
        free(game->map[i]);
    free(game->map);
    game->map = fill_tab(game->buffer);
    player_coords(game);
    display_map(game);
}

void loss_check(game_t *game)
{
    int j = 0;
    int count = 0;

    for (int i = 0; game->map[i] != NULL; ++j) {
        if (game->map[i][j] == 'X' &&
            ((game->map[i - 1][j] == '#' && game->map[i][j - 1] == '#') ||
            (game->map[i - 1][j] == '#' && game->map[i][j + 1] == '#') ||
            (game->map[i + 1][j] == '#' && game->map[i][j - 1] == '#') ||
            (game->map[i + 1][j] == '#' && game->map[i][j + 1] == '#')))
            count += 1;
        if (game->map[i][j] == '\n') {
            i += 1;
            j = 0;
        }
    }
    if (count == game->nb_o)
        free_all(game, 1);
}

void win_check(game_t *game)
{
    int count = 0;

    for (int i = 0; i < game->nb_o; ++i) {
        if (game->map[game->o_coords[i][0]][game->o_coords[i][1]] == 'X')
            count += 1;
    }
    if (count == game->nb_o)
        free_all(game, 0);
}

void holes_check(game_t *game)
{
    for (int i = 0; i < game->nb_o; ++i)
        if (game->map[game->o_coords[i][0]][game->o_coords[i][1]] == ' ')
            game->map[game->o_coords[i][0]][game->o_coords[i][1]] = 'O';
}

void game_fun(game_t *game)
{
    initscr();
    curs_set(FALSE);
    display_map(game);
    keypad(stdscr, TRUE);
    while (1) {
        game->key = getch();
        key_detection(game);
        holes_check(game);
        clear();
        display_map(game);
        win_check(game);
        loss_check(game);
    }
}