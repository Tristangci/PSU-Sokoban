/*
** EPITECH PROJECT, 2022
** maun
** File description:
** main
*/

#include "sokoban.h"

void left(struct base_t base)
{
    if (base.zap[base.x] == 'O')
        base.u = 'O';
    else
        base.u = ' ';
    cond_left(base);
}

void right(struct base_t base)
{
    if (base.zap[base.x] == 'O')
        base.u = 'O';
    else
        base.u = ' ';
    cond_right(base);
}

void upper(struct base_t base)
{
    if (base.zap[base.x] == 'O')
        base.u = 'O';
    else
        base.u = ' ';
    cond_up(base);
}

void down(struct base_t base)
{
    if (base.zap[base.x] == 'O')
        base.u = 'O';
    else
        base.u = ' ';
    cond_down(base);
}

int main(int ac, char **av)
{
    struct stat st;
    struct base_t base;
    if (ac != 2) return 84;
    if (av[1][1] == 'h') { display_h(); return 0; }
    stat(av[1], &st); int fd = open(av[1], O_RDONLY);
    if (fd == -1 || !S_ISREG(st.st_mode)) return 84;
    base.str = map(ac, av), base.zap = map(ac, av), base.init = map(ac, av);
    for (int i = 0; i != st.st_size; i++) {
        if (base.str[i] == 'P')
            base.x = i;
        if (base.str[i] == 'O')
            base.c++;
    } while (base.str[base.n] != '\n')
        base.n++;
    base.n++;
    initscr();
    return (game_loop(base));
}
