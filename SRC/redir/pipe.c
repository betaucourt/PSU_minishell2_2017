/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** get_line
*/

#include "include.h"
#include "ms2.h"
#include "struct.h"
#include "tools.h"

int is_piping_ok(char *str)
{
	if (my_strcmp(str, "|") == 1)
		return 1;
	if (my_strcmp(str, ">>") == 1)
		return 1;
	if (my_strcmp(str, ">") == 1)
		return 1;
	if (my_strcmp(str, "<") == 1)
		return 1;
	if (my_strcmp(str, "<") == 1)
		return 1;
	if (my_strcmp(str, ";") == 1)
		return 1;
	return 0;
}

void piping(t_cmd *cmd, t_env *env, int test2, char **tab)
{
int nb = 0;
int tab_nb = 0;

if (cmd->pars == 0) {
cmd->to_p[cmd->p_po] = malloc(sizeof(char *) * (strlen_tab(tab) + 1));
while (tab[tab_nb] != NULL) {
	if (is_piping_ok(tab[tab_nb]) == 1) {
		cmd->to_p[cmd->p_po][nb] = NULL;
		tab_nb++;
		nb = 0;
		cmd->p_po++;
		cmd->to_p[cmd->p_po] = malloc(sizeof(char *) * (strlen_tab(tab) + 1));
	}
	cmd->to_p[cmd->p_po][nb] = my_strcpy(tab[tab_nb]);
	tab_nb++;
	nb++;
}
cmd->to_p[cmd->p_po][nb] = NULL;
cmd->to_p[cmd->p_po += 1] = NULL;
}
cmd->pars++;
}
