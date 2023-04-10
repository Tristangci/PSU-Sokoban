/*
** EPITECH PROJECT, 2022
** up
** File description:
** up
*/

#include "sokoban.h"

void cond_up(struct base_t base)
{
    if (base.str[base.x - base.n] == ' ' || base.str[base.x - base.n] == 'O') {
        base.str[base.x] = base.u;
        base.str[base.x - base.n] = 'P';
        base.x -= base.n;
        game_loop(base);
    } else if (base.str[base.x - base.n] == 'X')
        x_up(base);
}

void cond_down(struct base_t base)
{
    if (base.str[base.x + base.n] == ' ' || base.str[base.x + base.n] == 'O') {
        base.str[base.x] = base.u;
        base.str[base.x + base.n] = 'P';
        base.x += base.n;
        game_loop(base);
    } else if (base.str[base.x + base.n] == 'X')
        x_down(base);
}

void cond_left(struct base_t base)
{
    if (base.str[base.x - 1] == ' ' || base.str[base.x - 1] == 'O') {
        base.str[base.x ] = base.u;
        base.str[base.x - 1] = 'P';
        base.x--;
        game_loop(base);
    } else if (base.str[base.x - 1] == 'X')
        x_left(base);
}

void cond_right(struct base_t base)
{
    if (base.str[base.x + 1] == ' ' || base.str[base.x + 1] == 'O') {
        base.str[base.x ] = base.u;
        base.str[base.x + 1] = 'P';
        base.x++;
        game_loop(base);
    } else if (base.str[base.x + 1] == 'X')
        x_right(base);
}
