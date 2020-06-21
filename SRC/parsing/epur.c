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

void cpy_to_cmd(char **tab, t_cmd **cmd)
{
	int tab_nb = 0;
	int cmd_nb = 0;

	while (tab[tab_nb] != NULL) {
		cmd[cmd_nb] = malloc(sizeof(t_cmd));
		cmd[cmd_nb]->right = malloc(sizeof(t_red));
		cmd[cmd_nb]->right->i = 0;
		cmd[cmd_nb]->left = malloc(sizeof(t_red));
		cmd[cmd_nb]->left->i = 0;
		cmd[cmd_nb]->tmp = my_strcpy(tab[tab_nb]);
		cmd[cmd_nb]->tmp = epur_str(cmd[cmd_nb]->tmp, ' ');
		cmd_nb++;
		tab_nb++;
	}
	cmd[cmd_nb] = NULL;
}

char **str_to_tab(char *str, char **tab, char c)
{
int tab_nb = 0;
int nb_nb = 0;
int check = 0;

tab[tab_nb] = malloc(sizeof(char) * (my_strlen(str) + 1));
for (int str_nb = 0 ; str[str_nb] != '\0'; str_nb++) {
	if (str[str_nb] == '"')
		check++;
	if (str[str_nb] == c && ((check % 2) == 0))	 {
		str_nb++;
		tab[tab_nb][nb_nb] = '\0';
		nb_nb = 0;
		tab_nb++;
		tab[tab_nb] = malloc(sizeof(char) * (my_strlen(str) + 1));
	}
	tab[tab_nb][nb_nb] = str[str_nb];
	nb_nb++;
}
tab[tab_nb][nb_nb] = '\0';
tab[tab_nb + 1] = NULL;
return tab;
}

int count_sep(char *str, char c)
{
	int str_nb = 0;
	int stock = 0;

	while (str[str_nb] != '\0') {
		if (str[str_nb] == c)
			stock++;
		str_nb++;
	}
	return stock;
}

char *put_off_tab(char *str)
{
	char *to_ret = malloc(sizeof(char) * (my_strlen(str) + 1));
	int str_nb = 0;
	int check = 0;

	while (str[str_nb] != '\0') {
		if (str[str_nb] == '"')
			check++;
		if (str[str_nb] == '\t' && (check % 2) == 0)
			str[str_nb] = ' ';
		to_ret[str_nb] = str[str_nb];
		str_nb++;
	}
	to_ret[str_nb] = '\0';
	return to_ret;
}

char	*epur_str (char *str, char sep)
{
	int		i = 0;
	int		j = 0;
	char *tab = malloc(sizeof(char) * (my_strlen(str) + 1));

	while (str[i] == sep)
		i++;
	while (str[i] != '\0') {
		if (str[i] == sep && str[i + 1] == sep)
			i++;
		else {
			tab[j] = str[i];
			j++;
			i++;
		}
		if ((str[i] == sep) && (str[i + 1] == '\0'))
			i++;
		tab[j] = str[i];
	}
	return (tab);
}
