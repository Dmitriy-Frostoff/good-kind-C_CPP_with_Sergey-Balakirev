// mode: c
#ifndef IS_WIN_H
#define IS_WIN_H

#include "config.h"

int check_xo_winner(const int *counter_x, const int *counter_o,
                    const int *counter_zero);

int count_x_o_zero(int *counter_x, int *counter_o, int *counter_zero,
                   const char *current_value);
int check_xo_rows(char (*arr)[SIZE]);
int check_xo_columns(char (*arr)[SIZE]);
int check_xo_left_diagonal(char (*arr)[SIZE]);
int check_xo_right_diagonal(char (*arr)[SIZE]);
int is_win(char (*arr)[SIZE]);

#endif
