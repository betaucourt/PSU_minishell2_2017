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

int get_line_env(char *cmd, char **env)
{
	int env_nb = 0;

	while (env[env_nb] != NULL) {
		if (check_str(cmd, env[env_nb]) == 1)
		return env_nb;
		env_nb++;
	}
	return -1;
}

char *get_first_part(char *str)
{
	char *to_ret = malloc(sizeof(char) * my_strlen(str));
	int nb = 0;

	while (str[nb] != '=') {
		to_ret[nb] = str[nb];
		nb++;
	}
	to_ret[nb] = '\0';
	return to_ret;
}

int check_str(char *cmd, char *env)
{
	int cmd_nb = 0;
	int env_nb = 0;
	char *str = get_first_part(env);

	if (my_strlen(cmd) != my_strlen(str))
		return 0;
	while (cmd[cmd_nb] != '\0') {
		if (cmd[cmd_nb] != env[env_nb])
			return 0;
		if (env[env_nb] == '=')
			return 0;
		cmd_nb++;
		env_nb++;
	}
	return 1;
}

char *get_this_line(char *str1, char *str2)
{
	int str1_nb = 0;
	int str2_nb = 0;
char *str = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 2));
	int str_nb = 0;

	while (str1[str1_nb] != '\0') {
		str[str_nb] = str1[str1_nb];
		str_nb++;
		str1_nb++;
	}
	str[str_nb] = '=';
	str_nb++;
	while (str2[str2_nb] != '\0') {
		str[str_nb] = str2[str2_nb];
		str_nb++;
		str2_nb++;
	}
	str[str_nb] = '\0';
	return str;
}
