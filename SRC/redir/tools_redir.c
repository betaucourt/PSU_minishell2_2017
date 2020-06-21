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

int suppress_redir(t_cmd *cmd, int tab_nb, int select)
{
	int nb = 0;
	int i = 0;

	if (select == 0)
		cmd->right->path = my_strcpy(cmd->cmd[tab_nb + 1]);
	if (select == 1)
		cmd->left->path = my_strcpy(cmd->cmd[tab_nb + 1]);
	while (cmd->cmd[nb] != NULL) {
		if (nb == tab_nb && (cmd->cmd[nb + 2])) {
			while (cmd->cmd[nb] != NULL && cmd->cmd[nb + 2]) {
				cmd->cmd[nb] = my_strcpy(cmd->cmd[nb + 2]);
				nb++;
			}
			i = 1;
		}
		if (i == 1)
		cmd->cmd[nb] = NULL;
		nb++;
	}
	return 0;
}
