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

int simple_right(t_cmd *cmd, t_env *env, int tab_nb, char **tab)
{
	cmd = cmd;
	env = env;
	tab_nb = tab_nb;
	if (!tab[tab_nb] || !tab[tab_nb + 1])
		my_putstr_r("Missing name for redirect.\n");
	return 0;
}
