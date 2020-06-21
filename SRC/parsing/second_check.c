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

char **epur_tab(char **tab)
{
	char **to_ret = malloc(sizeof(char *) * (strlen_tab(tab) + 3));
	int ret_nb = 0;
	int tab_nb = 0;

	while (tab[tab_nb] != NULL) {
		if (tab[tab_nb][0] == '\0')
			tab_nb++;
		to_ret[ret_nb] = my_strcpy(tab[tab_nb]);
		ret_nb++;
		tab_nb++;
	}
	to_ret[ret_nb] = NULL;
	return to_ret;
}

int split_redir(t_cmd *cmd)
{
	int nb = 0;

	while (cmd->tmp[nb] != '\0') {
		nb++;
	}
	return 1;
}

int is_redir(t_cmd *cmd, char *str)
{
		if (my_strcmp(str, ">") == 1) {
			cmd->pos[0] = 0;
			return 0;
		}
		if (my_strcmp(str, ">>") == 1) {
			cmd->pos[0] = 1;
			return 1;
		}
		if (my_strcmp(str, "<") == 1) {
			cmd->pos[0] = 2;
			return 2;
		}
		if (my_strcmp(str, "<<") == 1) {
			cmd->pos[0] = 3;
			return 3;
		}
		if (my_strcmp(str, "|") == 1) {
			cmd->pos[0] = 4;
			return 4;
		}
	return 5;
}

int check_redir(char **tab)
{
int l = 0;
int r = 0;
int tab_nb = 0;
int pos;

while (tab[tab_nb] != NULL) {
	if (my_strcmp(tab[tab_nb], ">>") || my_strcmp(tab[tab_nb], ">") == 1) {
		r++;
		pos = tab_nb;
	}
	if (my_strcmp(tab[tab_nb], "<") || my_strcmp(tab[tab_nb], "<<") == 1) {
		l++;
		pos = tab_nb;
	}
	if ((l > 0 || r > 0) && tab[pos + 1] == NULL)
		return 2;
	tab_nb++;
}
if ((l > 1 || r > 1) || (r > 1 && l > 1))
	return 0;
return 1;
}
