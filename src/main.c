/*
** EPITECH PROJECT, 2019
** my_popup
** File description:
** open a window and print the string in its middle
*/

#include "sokoban.h"
#include "my.h"

void free_exit(char *buffer, int fd)
{
    close(fd);
    free(buffer);
    exit(84);
}

void check_characters(char *buffer, int fd)
{
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] != '#' && buffer[i] != ' ' && buffer[i] != 'P' &&
        buffer[i] != 'O' && buffer[i] != 'X' && buffer[i] != '\n')
            free_exit(buffer, fd);
        i += 1;
    }
}

void map_integrity(char *buffer, int fd)
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
        free_exit(buffer, fd);
    check_characters(buffer, fd);
}

void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map, containing ");
    my_putstr("\'#\' for walls,\n");
    my_putstr("          'P\' for the player, \'X\' for boxes and \'O\' for ");
    my_putstr("storage locations.\n");
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        help();
    sokoban(av[1]);
    return (0);
}