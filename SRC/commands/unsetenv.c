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
#include "env.h"

char **get_new_env( t_env *env, int line)
{
	int env_nb = 0;
	char **new_env = malloc(sizeof(char *) * (strlen_tab(env->env)));
	int new_nb = 0;

	while (env->env[env_nb] != NULL) {
		if (env_nb == line && env->env[env_nb + 1] != NULL)
			env_nb++;
		else if (env_nb == line && env->env[env_nb + 1] == NULL) {
			new_env[new_nb] = NULL;
			return new_env;
		}
		new_env[new_nb] = my_strcpy(env->env[env_nb]);
		new_nb++;
		env_nb++;
	}
	new_env[new_nb] = NULL;
	return new_env;
}

int my_unsetenv(t_cmd **cmd, t_env *env, int cur)
{
	if (cmd[cur]->cmd[1] == NULL) {
	my_putstr_r("unsetenv: Too few arguments.\n");
	return 0;
	}
	int line = get_line_env(cmd[cur]->cmd[1], env->env);

	if (line == -1) {
		my_putstr_r("This NAME does not exist\n");
		return 0;
	}
	else if (line != -1) {
		env->env = get_new_env(env, line);
		return 0;
	}
	return 0;
}
