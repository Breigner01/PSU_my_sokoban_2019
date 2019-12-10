/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** manage movements
*/

#include "sokoban.h"
#include "my.h"

void move_up(game_t *game)
{
    if (game->map[game->p[0] - 1][game->p[1]] == ' ' ||
        game->map[game->p[0] - 1][game->p[1]] == 'O') {
        game->map[game->p[0]][game->p[1]] = ' ';
        game->map[game->p[0] - 1][game->p[1]] = 'P';
        game->p[0] -= 1;
    } else if (game->map[game->p[0] - 1][game->p[1]] == 'X' &&
                (game->map[game->p[0] - 2][game->p[1]] == ' ' ||
                game->map[game->p[0] - 2][game->p[1]] == 'O')) {
        game->map[game->p[0]][game->p[1]] = ' ';
        game->map[game->p[0] - 1][game->p[1]] = 'P';
        game->map[game->p[0] - 2][game->p[1]] = 'X';
        game->p[0] -= 1;
    }
}

void move_down(game_t *game)
{
    if (game->map[game->p[0] + 1][game->p[1]] == ' ' ||
        game->map[game->p[0] + 1][game->p[1]] == 'O') {
        game->map[game->p[0]][game->p[1]] = ' ';
        game->map[game->p[0] + 1][game->p[1]] = 'P';
        game->p[0] += 1;
    } else if (game->map[game->p[0] + 1][game->p[1]] == 'X' &&
                (game->map[game->p[0] + 2][game->p[1]] == ' ' ||
                game->map[game->p[0] + 2][game->p[1]] == 'O')) {
        game->map[game->p[0]][game->p[1]] = ' ';
        game->map[game->p[0] + 1][game->p[1]] = 'P';
        game->map[game->p[0] + 2][game->p[1]] = 'X';
        game->p[0] += 1;
    }
}

void move_right(game_t *game)
{
    if (game->map[game->p[0]][game->p[1] + 1] == ' ' ||
        game->map[game->p[0]][game->p[1] + 1] == 'O') {
        game->map[game->p[0]][game->p[1]] = ' ';
        game->map[game->p[0]][game->p[1] + 1] = 'P';
        game->p[1] += 1;
    } else if (game->map[game->p[0]][game->p[1] + 1] == 'X' &&
                (game->map[game->p[0]][game->p[1] + 2] == ' ' ||
                game->map[game->p[0]][game->p[1] + 2] == 'O')) {
        game->map[game->p[0]][game->p[1]] = ' ';
        game->map[game->p[0]][game->p[1] + 1] = 'P';
        game->map[game->p[0]][game->p[1] + 2] = 'X';
        game->p[1] += 1;
    }
}

void move_left(game_t *game)
{
    if (game->map[game->p[0]][game->p[1] - 1] == ' ' ||
        game->map[game->p[0]][game->p[1] - 1] == 'O') {
        game->map[game->p[0]][game->p[1]] = ' ';
        game->map[game->p[0]][game->p[1] - 1] = 'P';
        game->p[1] -= 1;
    } else if (game->map[game->p[0] ][game->p[1] - 1] == 'X' &&
                (game->map[game->p[0]][game->p[1] - 2] == ' ' ||
                game->map[game->p[0]][game->p[1] - 2] == 'O')) {
        game->map[game->p[0]][game->p[1]] = ' ';
        game->map[game->p[0]][game->p[1] - 1] = 'P';
        game->map[game->p[0]][game->p[1] - 2] = 'X';
        game->p[1] -= 1;
    }
}

void key_detection(game_t *game)
{
    switch (game->key) {
    case KEY_UP:
        move_up(game);
        break;
    case KEY_DOWN:
        move_down(game);
        break;
    case KEY_RIGHT:
        move_right(game);
        break;
    case KEY_LEFT:
        move_left(game);
        break;
    case 32:
        reset_map(game);
        break;
    case 27:
        free_all(game, 0);
        break;
    }
}