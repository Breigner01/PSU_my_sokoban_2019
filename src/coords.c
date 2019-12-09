/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** manage coordinates
*/

#include "my.h"
#include "sokoban.h"

int store_holes_coords(struct game_struct *game, int count, int *i)
{
    if (game->map[i[0]][i[1]] == 'O') {
        game->o_coords[count] = malloc(sizeof(int) * 2);
        game->o_coords[count][0] = i[0];
        game->o_coords[count][1] = i[1];
        count += 1;
    }
    return (count);
}

void find_holes(game_t *game, int i[2])
{
    if (game->map[i[0]][i[1]] == 'O')
        game->nb_o += 1;
}

void find_holes_coords(struct game_struct *game)
{
    int count = 0;
    int i[2] = {0, 0};

    game->nb_o = 0;
    for (; game->map[i[0]] != NULL; ++i[0])
        for (i[1] = 0; game->map[i[0]][i[1]] != '\0'; ++i[1])
            find_holes(game, i);
    game->o_coords = malloc(sizeof(int *) * game->nb_o);
    if (game->o_coords == NULL)
        exit(84);
    for (i[0] = 0; game->map[i[0]] != NULL; ++i[0])
        for (i[1] = 0; game->map[i[0]][i[1]] != '\0'; ++i[1])
            count = store_holes_coords(game, count, i);
}

void player_coords(struct game_struct *game)
{
    int j = 0;

    for (int i = 0; game->map[i] != NULL; ++j) {
        if (game->map[i][j] == 'P') {
            game->p[0] = i;
            game->p[1] = j;
            return;
        }
        if (game->map[i][j] == '\n') {
            i += 1;
            j = 0;
        }
    }
}