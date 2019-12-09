/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** header file
*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <ncurses.h>
#include <curses.h>

typedef struct game_struct {
    char **map;
    char *buffer;
    int **o_coords;
    int nb_o;
    int p[2];
    int key;
    int x;
    int y;
} game_t;

void sokoban(char *);
void find_holes_coords(game_t *);
void key_detection(game_t *);
void player_coords(game_t *);
void game_fun(game_t *);
void display_map(game_t *);
void map_integrity(char *);
void reset_map(game_t *);

#endif