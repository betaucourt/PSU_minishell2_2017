/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#include "include.h"
#include "ms2.h"
#include "tools.h"

typedef struct S_env
{
	char **env;
	char *pwd;
	char *oldpwd;
	char **path;
	int is_empty;
	int size;
}	t_env;

typedef struct S_red
{
	int i;
	int s_o_d;
	char *path;
	char **to_write;
}	t_red;

typedef struct S_cmd
{
	int env;
	int *pos;
	int is_next;
	int p_po;
	char *tmp;
	char **cmd;
	t_red *right;
	t_red *left;
	char ***to_p;
	int *is_pipe;
	int last[2];
	int fd[2];
	int pars;
	int check;
	int status;
}	t_cmd;

typedef struct {
	int (*numero[6])(t_cmd **cmd, t_env *env, int cur);
}	choice;

typedef struct {
	int (*numero[5])();
}	redir;

int my_cd(t_cmd **cmd, t_env *env, int cur);
int my_setenv(t_cmd **cmd, t_env *env, int cur);
int my_unsetenv(t_cmd **cmd, t_env *env, int cur);
int my_env(t_cmd **cmd, t_env *env, int cur);

#endif
