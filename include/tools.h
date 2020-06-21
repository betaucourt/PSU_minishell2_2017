/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#ifndef TOOLS_H_
# define TOOLS_H_

#include "include.h"
#include "ms2.h"
#include "struct.h"

# define READ_SIZE (1)
int my_strlen(char *str);
int strlen_t_tab(char ***tab);
int strlen_tab(char **tab);
int my_strcmp(char *str1, char *str2);
char *my_strcpy(char *str);
char *my_strcat(char *dest, char *src);
char *my_revstr(char *str);
void my_putstr(char *str);
char *get_next_line(int fd);
int my_atoi(char *str);
int	my_put_nbr(int nb);
void my_putstr_r(char *str);
char **cpy_tab(char **tab);

#endif
