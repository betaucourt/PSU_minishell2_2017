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

int exec_with_path(char *str, t_cmd *cmd, t_env *env, char **path)
{
	char *to_test;
	int nb = 0;
	pid_t pid;
	int status;

	while (path[nb] != NULL) {
		to_test = my_strcat_path(path[nb], str);
		if (access(to_test, F_OK) == 0) {
			pid = fork();
			if (pid == 0) {
				execve(to_test, cmd->cmd, env->env);
			} else
				wait(&status);
			get_status();
			return 0;
		}
		nb++;
	}
	get_status();
	return 1;
}

void get_it()
{
}

void get_status(void)
{
	int status;

	signal(SIGINT, get_it);
	wait(&status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 11)
			write(2, "Segmentation Fault !\n", 21);
		else if (WTERMSIG(status) == 8)
			write(2, "Arithmetic exception\n", 21);
	}
	else if (WIFSTOPPED(status))
		write(2, "No more = STOP\n", 15);
}
int exec_w_fork(char *str, t_cmd *cmd, t_env *env, int nb)
{
	pid_t pid;
	char **path;
	int status;

	if (nb == 0) {
		pid = fork();
		if (pid == 0) {
			execve(str, cmd->cmd, env->env);
		} else {
		get_status();
			wait(&status);
		}
	}
	else if (nb == 1) {
		if ((path = get_path(env->env)) == NULL)
			return -1;
		exec_with_path(cmd->cmd[0], cmd, env, path);
	}
	return 0;
}
