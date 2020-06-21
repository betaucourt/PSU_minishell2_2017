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

int nb_pipe(char **tab)
{
	int pipe = 0;
	int tab_nb = 0;

	while (tab[tab_nb] != NULL) {
		if (my_strcmp(tab[tab_nb], "|") == 1)
			pipe++;
		tab_nb++;
	}
	return pipe;
}

void init_red(redir *red, t_cmd *cmd)
{
	red->numero[0] = &simple_right;
	red->numero[1] = &double_right;
	red->numero[2] = &simple_left;
	red->numero[3] = &double_left;
	red->numero[4] = &piping;
	cmd->pos = malloc(sizeof(int) * 5);
	cmd->is_pipe = malloc(sizeof(int) * (nb_pipe(cmd->cmd)));
}

char **pars_redir(char **input, t_cmd *cmd, t_env *env)
{
	int tab_nb = 0;
	int to_ret = 0;
	redir red;
	char **tab = cpy_tab(input);

	cmd->cmd = cpy_tab(tab);
	cmd->pars = 0;
	init_red(&red, cmd);
	cmd->to_p = malloc(sizeof(char **) * (10000));
	while (cmd->cmd[tab_nb] != NULL) {
		if ((to_ret = is_redir(cmd, tab[tab_nb])) != 5) {
			red.numero[to_ret](cmd, env, (tab_nb), tab);
			tab_nb++;
		}
		tab_nb++;
	}
	return NULL;
}

int split_pipe_redir(t_cmd *cmd, t_env *env)
{
	int to_ret = 0;
	char **tab = malloc(sizeof(char *) * (count_sep(cmd->tmp, ' ') + 2));

	tab = str_to_tab(cmd->tmp, tab, ' ');
	if ((to_ret = check_redir(tab)) != 1) {
		if (to_ret == 0)
			my_putstr_r("Ambiguous input redirect.\n");
		if (to_ret == 2)
			my_putstr_r("Missing name for redirect.\n");
		return 0;
	}
	pars_redir(tab, cmd, env);
	return 1;
}

int prepare_exec(t_cmd **cmd, t_env *env)
{
	int cmd_nb = 0;

	while (cmd[cmd_nb] != NULL) {
		cmd[cmd_nb]->p_po = 0;
		if (split_pipe_redir(cmd[cmd_nb], env) == 0)
			return 0;
		cmd_nb++;
	}
	execut_commands(cmd, env);
	return 1;
}
