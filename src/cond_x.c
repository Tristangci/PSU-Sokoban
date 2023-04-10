/*
** EPITECH PROJECT, 2022
** xee
** File description:
** xee
*/

#include "sokoban.h"

void x_up(struct base_t base)
{
    if (base.str[base.x - base.n * 2] == ' ') {
        base.str[base.x] = base.u;
        base.str[base.x - base.n] = 'P';
        base.str[base.x - base.n * 2] = 'X';
        base.x -= base.n;
        game_loop(base);
    } if (base.str[base.x - base.n * 2] == 'O') {
        base.str[base.x] = base.u;
        base.str[base.x - base.n] = 'P';
        base.str[base.x - base.n * 2] = 'X';
        base.x -= base.n;
        game_loop(base);
    }
}

void x_down(struct base_t base)
{
    if (base.str[base.x + base.n * 2] == ' ') {
        base.str[base.x] = base.u;
        base.str[base.x + base.n] = 'P';
        base.str[base.x + base.n * 2] = 'X';
        base.x += base.n;
        game_loop(base);
    } if (base.str[base.x + base.n * 2] == 'O') {
        base.str[base.x] = base.u;
        base.str[base.x + base.n] = 'P';
        base.str[base.x + base.n * 2] = 'X';
        base.x += base.n;
        game_loop(base);
    }
}

void x_left(struct base_t base)
{
    if (base.str[base.x - 2] == ' ') {
        base.str[base.x ] = base.u;
        base.str[base.x - 1] = 'P';
        base.str[base.x - 2] = 'X';
        base.x--;
        game_loop(base);
    } if (base.str[base.x - 2] == 'O') {
        base.str[base.x ] = base.u;
        base.str[base.x - 1] = 'P';
        base.str[base.x - 2] = 'X';
        base.x--;
        game_loop(base);
    }
}

void x_right(struct base_t base)
{
    if (base.str[base.x + 2] == ' ') {
        base.str[base.x ] = base.u;
        base.str[base.x + 1] = 'P';
        base.str[base.x + 2] = 'X';
        base.x++;
        game_loop(base);
    } if (base.str[base.x + 2] == 'O') {
        base.str[base.x ] = base.u;
        base.str[base.x + 1] = 'P';
        base.str[base.x + 2] = 'X';
        base.x++;
        game_loop(base);
    }
}
