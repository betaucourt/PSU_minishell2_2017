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
char **get_bigger(t_cmd *cmd, t_env *env)
{
	int env_nb = 0;
	int new_nb = 0;

	char **new_env = malloc(sizeof(char *) * (strlen_tab(env->env) + 2));

	while (env->env[env_nb] != NULL) {
		new_env[new_nb] = my_strcpy(env->env[env_nb]);
		new_nb++;
		env_nb++;
	}
	new_env[new_nb] = get_this_line(cmd->cmd[1], cmd->cmd[2]);
	new_env[new_nb + 1] = NULL;
	return new_env;
}

void change_elem(t_cmd *cmd, t_env *env, int line)
{
	int env_nb = 0;
	int cmd_nb = 0;

	while (cmd->cmd[1][cmd_nb] != '\0') {
		env->env[line][env_nb] = cmd->cmd[1][cmd_nb];
		cmd_nb++;
		env_nb++;
	}
	env->env[line][env_nb] = '=';
	env_nb++;
	cmd_nb = 0;
	while (cmd->cmd[2][cmd_nb] != '\0') {
		env->env[line][env_nb] = cmd->cmd[2][cmd_nb];
		cmd_nb++;
		env_nb++;
	}
	env->env[line][env_nb + 1] = '\0';
}

int my_setenv(t_cmd **cmd, t_env *env, int cur)
{
	if (cmd[cur]->cmd[1] == NULL) {
		my_putstr_r("setenv: Too few arguments.\n");
		return 0;
	}
	int line = get_line_env(cmd[cur]->cmd[1], env->env);

	if (line == -1) {
		env->env = get_bigger(cmd[cur], env);
		return 0;
	}
	if (line != -1) {
		change_elem(cmd[cur], env, line);
		return 0;
	}
	return 0;
}
