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

int basic_check(char *str)
{
	if (my_strlen(str) < 40)
		return 1;
	if (my_strcmp(str, "cd"))
		return 1;
	return 0;
}

void sigintHandler()
{
	if (signal(SIGINT, sigintHandler))
		write(1, "\n", 7);
}

int is_exit(char *str)
{
	if (my_strcmp(str, "exit") == 1)
		return 0;
	char **to_test = malloc(sizeof(char *) * my_strlen(str));
	int nb = 0;

	to_test = str_to_tab(str, to_test, ' ');
	while (to_test[nb] != NULL) {
		if (my_strcmp(to_test[nb], "exit") == 1)
			return (my_atoi(to_test[nb + 1]));
		nb ++;
	}
	return -109;
}

int big_bad_loop(t_env *env)
{
	t_cmd **cmd;
	char *str;
	char *input;
	int size;
	int nb = 0;

	signal(SIGINT, sigintHandler);
	put_prompt(env);
	while ((input = get_next_line(0)) != NULL) {
		if (basic_check(input) == 0)
			break;
		str = put_off_tab(input);
		str = epur_str(input, ' ');
		if ((nb = is_exit(str)) != -109)
			return nb;
		size = get_size(str);
		cmd = malloc(sizeof(t_cmd*) * (size + 3));
		nb = do_all(str, cmd, env);
		put_prompt(env);
	}
	return nb;
}


int main(int ac, char **av, char **env)
{
	if (ac != 1)
		return 84;
	int to_ret;
	t_env *my_env = malloc(sizeof(t_env));

	deal_with_env(my_env, env);
	to_ret = big_bad_loop(my_env);
	return to_ret;
}
