/*
** EPITECH PROJECT, 2019
** lib
** File description:
** count the length of a line
*/

int count_line_len(const char *str)
{
    int i = 0;

    while (str[i] != '\n')
        i += 1;
    return (i);
}