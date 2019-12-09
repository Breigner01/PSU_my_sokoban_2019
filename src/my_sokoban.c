/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

void display_map(game_t *game)
{
    if (LINES < game->y || COLS < game->x)
        mvprintw((LINES - 1) / 2, (COLS - 10) / 2, "Too Small!");
    else
        for (int i = 0; game->map[i] != NULL; ++i)
            mvprintw(((LINES - game->y) / 2) + i, (COLS - game->x) / 2,
                        game->map[i]);
    refresh();
}

void sokoban(char *filepath)
{
    struct stat stat_info;
    game_t game;
    int fd = open(filepath, O_RDONLY);

    stat(filepath, &stat_info);
    game.buffer = malloc(stat_info.st_size + 1);
    if (fd == -1 || stat_info.st_size == 0 ||
        read(fd, game.buffer, stat_info.st_size) == -1)
        exit(84);
    game.buffer[stat_info.st_size] = '\0';
    map_integrity(game.buffer);
    game.map = fill_tab(game.buffer);
    game.x = count_line_len(game.buffer);
    game.y = count_line_nb(game.buffer);
    player_coords(&game);
    find_holes_coords(&game);
    game_fun(&game);
}