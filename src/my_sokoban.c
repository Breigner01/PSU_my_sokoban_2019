/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** sokoban
*/

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

void compute_size(char *buffer, int (*size)[2])
{
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            (*size)[0] += 1;
        i += 1;
    }
    i = 0;
    while (buffer[i] != '\n')
        (*size)[1] += 1;
}

void fill_tab(char *buffer, char ***tab)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int size[2] = {0, 0};

    compute_size(buffer, &size);
    tab = malloc(sizeof(char *) * size[0]);
    while (buffer[i] != '\0') {
        (*tab)[j] = malloc(sizeof(char) * (size[1] + 1));
        while (buffer[i] != '\n') {
            tab[j][k] = buffer[i];
            i += 1;
            k += 1;
        }
        tab[j][k] = '\n';
        tab[j][k + 1] = '\0';
        k = 0;
        j += 1;
        i += 1;
    }
}

void map_integrity(char *buffer)
{
    int nb_p = 0;
    int nb_x = 0;
    int nb_o = 0;

    for (int i = 0; buffer[i] != '\0'; ++i) {
        switch (buffer[i]) {
        case 'P':
            nb_p += 1;
            break;
        case 'X':
            nb_x += 1;
            break;
        case 'O':
            nb_o += 1;
            break;
        }
    }
    if (nb_p != 1 || nb_x != nb_o)
        exit(84);
}

int sokoban(char *filepath)
{
    struct stat stat_info;
    int fd = open(filepath, O_RDONLY);
    int check = 0;
    char *buffer = malloc(sizeof(char) * (stat_info.st_size + 1));
    char **tab;
    int **coords;

    if (fd == -1 || stat_info.st_size == 0 ||
        read(fd, buffer, stat_info.st_size) == -1)
        exit(84);
    map_integrity(buffer);
    fill_tab(buffer, &tab);
    find_holes_coords(tab, &coords);
    display_map(tab, tab);
}