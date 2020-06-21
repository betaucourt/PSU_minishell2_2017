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

int move_cursor(char *str)
{
	int str_nb = 0;

	while (str[str_nb] != '"') {
		str_nb++;
	}
	return str_nb;
}

int check_quote(char *str)
{
	int nb = 0;
	int stock = 0;

	while (str[nb] != '\0') {
		if (str[nb] == '"')
			stock++;
		nb++;
	}
	if ((stock % 2) == 0)
		return 0;
	my_putstr_r("Unmatched '\"'.\n");
	return 1;
}

int check_pipe(char *str)
{
	int str_nb = 0;

	while (str[str_nb] != '\0') {
		if (str[str_nb] == '|' && str[str_nb + 1] == '\0')
			return 1;
		if (str[str_nb] == '|' && str[str_nb + 1] == '|' &&
			str[str_nb + 2] == '|')
			return 1;
		if (str[str_nb] == '|' && str[str_nb + 1] == ' ' &&
			(str[str_nb + 2] == '|' || str[str_nb + 2] == '\0'))
			return 1;
		str_nb++;
	}
	return 0;
}

int str_check(char *str)
{
	int str_nb = 0;

	if (check_quote(str) == 1)
		return 0;
	if (check_pipe(str) == 1) {
		my_putstr_r("Invalid null command.\n");
		return 0;
	}
	while (str[str_nb] != '\0') {
		if (str[str_nb] == '"')
			str_nb += move_cursor(&str[str_nb]);
		str_nb++;
	}
	return 1;
}
