/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** hunter
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <ncurses.h>
#include <fcntl.h>
#include <dirent.h>

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_

typedef struct base_t {
        char *str;
        char *zap;
        char *init;
        int x;
        int c;
        int count;
        int n;
        char u;
} base_t;

int main(int ac, char **av);
char *map(int ac, char **av);
int game_loop(struct base_t base);
void upper(struct base_t base);
void down(struct base_t base);
void right(struct base_t base);
void left(struct base_t base);
void cond_up(struct base_t base);
void cond_down(struct base_t base);
void cond_left(struct base_t base);
void cond_right(struct base_t base);
void x_down(struct base_t base);
void x_up(struct base_t base);
void x_left(struct base_t base);
void x_right(struct base_t base);
void display_win(void);
int verif_win(struct base_t base);
void display_h(void);
void reset(struct base_t base);

#endif /* !SOKOBAN_H_ */
