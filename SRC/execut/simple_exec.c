/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** get_line
*/

#include "include.h"
#include "ms2.h"
#include "struct.h"
#include "tools.h"

char **get_flags(choice *choose)
{
	char **flags = malloc(sizeof(char *) * 5);

	flags[0] = my_strcpy("cd");
	flags[1] = my_strcpy("env");
	flags[2] = my_strcpy("setenv");
	flags[3] = my_strcpy("unsetenv");
	flags[4] = NULL;
	choose->numero[0] = &my_cd;
	choose->numero[1] = &my_env;
	choose->numero[2] = &my_setenv;
	choose->numero[3] = &my_unsetenv;
	return flags;
}

int do_with_redir(t_cmd *cur, t_env *env, t_cmd **cmd, int pos)
{
if (cur->is_pipe == 0 || (cur->left->i == 0 || cur->right->i == 0)) {
	if (cur->cmd[0] && cur->cmd[0][0] == '.' && cur->cmd[0][1] == '/')
		exec_w_fork(cur->cmd[0], cmd[pos], env, 0);
	else if (cur->cmd[0] && cur->cmd[0][0] != '.' && cur->cmd[0][1] != '/')
		exec_w_fork(cur->cmd[0], cmd[pos], env, 1);
}
return 0;
}

int redirect_cmd(t_cmd **cmd, t_env *env, int cur)
{
	choice choose;
	char **flags = get_flags(&choose);
	int nb = 0;

	while (flags[nb] != NULL) {
		if (my_strcmp(cmd[cur]->cmd[0], flags[nb])) {
			choose.numero[nb](cmd, env, cur);
			return 0;
		}
		nb++;
	}
	do_with_redir(cmd[cur], env, cmd, cur);
	return 0;
}
