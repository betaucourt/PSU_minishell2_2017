/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** env
*/

#include "ms2.h"
#include "tools.h"
#include "struct.h"
#include "include.h"

int my_env(t_cmd **cmd, t_env *env, int cur)
{
	int nb = 0;

	if (cmd[cur]->cmd[1] != NULL) {
		my_putstr_r("env: '");
		my_putstr_r(cmd[cur]->cmd[1]);
		my_putstr("': No such file or directory\n");
		return 0;
	}
	while (env->env[nb] != NULL) {
		my_putstr(env->env[nb]);
		my_putstr("\n");
		nb++;
	}
	return 0;
}
