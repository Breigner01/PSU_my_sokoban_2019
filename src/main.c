/*
** EPITECH PROJECT, 2019
** my_popup
** File description:
** open a window and print the string in its middle
*/

#include "sokoban.h"
#include "my.h"

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

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    sokoban(av[1]);
    return (0);
}