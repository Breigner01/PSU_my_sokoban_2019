/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** manage the holes
*/

#include "my.h"

int store_holes_coords(char **tab, int ***coords, int count, int *i)
{
    if (tab[i[0]][i[1]] == 'O') {
        (*coords)[count] = malloc(sizeof(int) * 2);
        (*coords)[count][0] = i[0];
        (*coords)[count][1] = i[1];
        ++count;
    }
    return (count);
}

int find_holes(char c, int ***coords, int nb_holes)
{
    if (c == 'O')
        nb_holes += 1;
    return (nb_holes);
}

void find_holes_coords(char **tab, int ***coords)
{
    int nb_holes = 0;
    int count = 0;
    int i[2] = {0, 0};

    for (; tab[i[0]] != NULL; ++i[0]) {
        for (i[1] = 0; tab[i[0]][i[1]] != '\0'; ++i[1])
            nb_holes = find_holes(tab[i[0]][i[1]], coords, nb_holes);
    (*coords) = malloc(sizeof(int *) * nb_holes);
    for (i[0] = 0; tab[i[0]] != NULL; ++i[0])
        for (i[1] = 0; tab[i[0]][i[1]] != '\0'; ++i[1])
            count = store_holes_coords(tab, coords, count, i);
}