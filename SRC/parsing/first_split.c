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

int get_size(char *str)
{
	int str_nb = 0;
	int check = 0;
	int size = 0;

	while (str[str_nb] != '\0') {
		if (str[str_nb] == '"')
			check++;
		if (str[str_nb] == ';' && ((check % 2) == 0))
			size++;
		str_nb++;
		}
	return size;
}

char *epur_error(char *str)
{
	int str_nb = 0;

	while (str[str_nb] != '\0') {
		if (str[str_nb] < 0)
			str[str_nb] = ' ';
		str_nb++;
	}
	return str;
}

void split_with_dot(char *str, t_cmd **cmd)
{
	char **tab = malloc(sizeof(char *) * (count_sep(str, ';') + 2));

	str = epur_error(str);
	tab = str_to_tab(str, tab, ';');
	cpy_to_cmd(tab, cmd);
}


int do_all(char *str, t_cmd **cmd, t_env *env)
{
	if (str_check(str) == 0)
		return 1;
	split_with_dot(str, cmd);
	if (prepare_exec(cmd, env) == 0)
		return 1;
	return 0;
}
