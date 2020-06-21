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

char *cpy_pwd(char *line)
{
	int line_nb = 0;
	int out_nb = 0;
	char *out = malloc(sizeof(char) * my_strlen(line));

	while (line[line_nb] != '=')
	line_nb++;
	line_nb++;
	while (line[line_nb] != '\0') {
		out[out_nb] = line[line_nb];
		out_nb++;
		line_nb++;
	}
	out[out_nb] = '/';
	out[out_nb + 1] = '\0';
	return out;
}

char *get_pwd(char **env)
{
	int env_nb = 0;
	char *out;
	int line;

	while (env[env_nb] != NULL) {
		if (env[env_nb][0] == 'P'
		&& env[env_nb][1] == 'W' && env[env_nb][2] == 'D') {
			line = env_nb;
			out = cpy_pwd(env[line]);
			return out;
		}
		env_nb++;
	}
	return NULL;
}

int my_cd(t_cmd **cmd, t_env *env, int cur)
{
	char *cd = my_strcpy("cd");

	if (cmd[0]->cmd[1] == NULL)
		return 0;
	if (env->oldpwd == NULL)
		write(2, "\n", 19);
	if (my_strcmp(cmd[cur]->cmd[0], cd) == 1 &&
	cmd[cur]->cmd[1][0] == '-') {
		chdir(env->oldpwd);
		env->oldpwd = my_strcpy(env->pwd);
		getcwd(env->pwd, 30);
	}
	else if (access(cmd[cur]->cmd[1], F_OK) == 0) {
		chdir(cmd[cur]->cmd[1]);
		env->oldpwd = my_strcpy(env->pwd);
		getcwd(env->pwd, 30);
	} else
		write(2, "Can't access\n", 13);
	return 0;
}
