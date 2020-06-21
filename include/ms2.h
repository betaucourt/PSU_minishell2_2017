/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#ifndef MS2_H_
# define MS2_H

#include "include.h"
#include "struct.h"
#include "tools.h"

int get_size(char *str);

void put_prompt();
void deal_with_env();
int do_all();
int str_check(char *str);
int move_cursor(char *str);
char *put_off_tab(char *str);
char *epur_str(char *input, char c);
char **str_to_tab(char *str, char **tab, char c);
int count_sep(char *str, char c);
int prepare_exec();
void cpy_to_cmd();
char **epur_tab(char **tab);
int check_redir(char **tab);
void break_it();
char **cpy_tab_to_cmd();
int split_redir();
int is_redir();

int redirect_cmd();
char *get_this_line(char *str1, char *str2);
int check_str(char *cmd, char *env);
char *get_first_part(char *str);
int get_line_env(char *cmd, char **env);

int my_cd();
int my_env();
int my_setenv();
int my_unsetenv();

void get_status(void);

char **get_path(char **env);
char *my_strcat_path(char *dest, char *src);

int exec_w_fork();
int exec_with_path();

int execut_commands();
int double_left();
void piping();
int double_right();
int simple_left();
int simple_right();
int suppress_redir();
#endif
