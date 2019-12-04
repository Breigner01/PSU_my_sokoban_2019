/*
** EPITECH PROJECT, 2019
** my_popup
** File description:
** open a window and print the string in its middle
*/

#include <ncurses.h>
#include "my.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    sokoban(av[1]);
    return (0);
}