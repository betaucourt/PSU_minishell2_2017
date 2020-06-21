/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** main
*/

#include "ms2.h"
#include "include.h"
#include "struct.h"
#include "tools.h"

int my_strlen(char *str)
{
	int nb = 0;

	while (str[nb] != '\0')
		nb++;
	return nb;
}

int strlen_tab(char **tab)
{
	int tab_nb = 0;

	while (tab[tab_nb] != NULL)
		tab_nb++;
	return tab_nb;
}

int strlen_t_tab(char ***tab)
{
	int nb = 0;

	while (tab[nb] != NULL)
		nb++;
	return nb;
}

int my_strcmp(char *str1, char *str2)
{
	int str1_nb = 0;

	if (my_strlen(str1) != my_strlen(str2))
		return 0;
	while (str1[str1_nb] != '\0') {
		if (str1[str1_nb] != str2[str1_nb])
		return 0;
		str1_nb++;
	}
	return 1;
}

char *my_strcpy(char *str)
{
	int str_nb = 0;
	char *out = malloc(sizeof(char) * (my_strlen(str) + 1));
	int out_nb = 0;

	while (str[str_nb] != '\0') {
		out[out_nb] = str[str_nb];
		out_nb++;
		str_nb++;
	}
	out[out_nb] = '\0';
	return out;
}
