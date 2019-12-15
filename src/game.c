/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** game part
*/

#include "my.h"
#include "sokoban.h"

int count_blocked_boxes(game_t *game, int i, int j, int count)
{
    char c_1 = game->map[i - 1][j];
    char c_2 = game->map[i][j - 1];
    char c_3 = game->map[i][j + 1];
    char c_4 = game->map[i + 1][j];

    if (game->map[i][j] == 'X' && (((c_4 == '#' || c_4 == 'X') || (c_1 == '#' ||
    c_1 == 'X')) && ((c_2 == '#' || c_2 == 'X') || (c_3 == '#' || c_3 == 'X'))))
        count += 1;
    return (count);
}

void loss_check(game_t *game)
{
    int j = 0;
    int count = 0;

    for (int i = 0; game->map[i] != NULL; ++j) {
        if ((j + 1) < game->x && (i + 1) < game->y && j > 0 && i > 0)
            count = count_blocked_boxes(game, i, j, count);
        if (game->map[i][j] == '\n' || game->map[i][j] == '\0') {
            i += 1;
            j = 0;
        }
    }
    if (count >= game->nb_o)
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