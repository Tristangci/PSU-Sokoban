/*
** EPITECH PROJECT, 2022
** func
** File description:
** func
*/

#include "sokoban.h"

char *map(int ac, char **av)
{
    struct stat st;
    stat(av[1], &st);
    int fd = open(av[1], O_RDONLY), x = 0;
    char *str = malloc(st.st_size + 1);
    for (int i = 0; i != st.st_size; i++) {
        char c;
        read(fd, &c, 1);
        str[i] = c;
        if (str[i] == 'P')
            x = i;
    }
    return str;
}

int verif_win(struct base_t base)
{
    base.count = 1;
    for (int i = 0; base.zap[i] != '\0'; i++)
        if (base.zap[i] == 'O' && base.str[i] == 'X')
            base.count++;
    if (base.count == base.c + 1)
        return 1;
    return 0;
}

int game_loop(struct base_t base)
{
    clear();
    int i = 0;
    mvprintw(0, 0, base.str);
    while (verif_win(base) != 1) {
        i = getch();
        if (i == 32)
            reset(base);
        if (i == 68)
            left(base);
        if (i == 67)
            right(base);
        if (i == 65)
            upper(base);
        if (i == 66)
            down(base);
        refresh();
    }
    endwin();
    return 0;
}

void display_h(void)
{
    write(1, "USAGE\n", 6);
    write(1, "\t./my_sokoban map\n", 18);
    write(1, "DESCRIPTION\n", 12);
    write(1, "\tmap file representing the warehouse map,", 41);
    write(1, " containing '#' for walls,\n", 27);
    write(1, "\t    'P' for the player,", 25);
    write(1, " 'X' for boxes and 'O' for storage locations.\n", 47);
}

void reset(struct base_t base)
{
    for (int i = 0; base.init[i] != '\0'; i++) {
        base.str[i] = base.init[i];
        base.zap[i] = base.init[i];
        if (base.str[i] == 'P')
            base.x = i;
    }
    game_loop(base);
}
