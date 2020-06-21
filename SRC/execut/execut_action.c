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

int is_cmd_ok(char **path, char *cmd)
{
	int nb = 0;
	char *to_test;

	while (path[nb] != NULL) {
		to_test = my_strcat_path(path[nb], cmd);
		if (access(to_test, F_OK) == 0)
			return nb;
		nb++;
	}
	return -1;
}

void put_pipe_error(char *str)
{
	my_putstr_r(str);
	my_putstr_r(": Command not found.\n");
}

void exec_w_pipe(t_cmd *cmd, t_env *env)
{
char **path = get_path(env->env);
char *to_test;
int fd_in = 0;
int pipe_nb = 0;
int path_nb = -1;
pid_t pid;

pipe(cmd->fd);
while (cmd->to_p[pipe_nb] != NULL) {
	if ((path_nb = is_cmd_ok(path, cmd->to_p[pipe_nb][0])) != -1) {
		to_test = my_strcat_path(path[path_nb], cmd->to_p[pipe_nb][0]);
		pid = fork();
		if (pid == 0) {
			dup2(fd_in, 0);
			if (cmd->to_p[pipe_nb + 1] != NULL)
				dup2(cmd->fd[1], 1);
			close (cmd->fd[0]);
			execve(to_test, cmd->to_p[pipe_nb], env->env);
		} else {
			wait(NULL);
			close(cmd->fd[1]);
			fd_in = cmd->fd[0];
			pipe_nb++;
		}
	} else {
		put_pipe_error(cmd->to_p[pipe_nb][0]);
		break;
	}
	path_nb = -1;
}
}

int execut_commands(t_cmd **cmd, t_env *env)
{
	int cmd_nb = 0;

	while (cmd[cmd_nb] != NULL) {
		if (cmd[cmd_nb]->to_p[0] == NULL) {
			redirect_cmd(cmd, env, cmd_nb);
		}
		else {
			exec_w_pipe(cmd[cmd_nb], env);
		}
		cmd_nb++;
	}
	return 0;
}
