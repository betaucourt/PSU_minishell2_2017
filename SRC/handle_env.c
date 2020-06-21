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

void null_env(t_env *my_env)
{
	my_env->pwd = malloc(sizeof(char) * 30);
	getcwd(my_env->pwd, 30);
	my_env->env = malloc(sizeof(char *) * 2);
	my_env->env[0] = NULL;
	my_env->is_empty = 0;
}

char **cpy_env(char **env)
{
	char **to_ret = malloc(sizeof(char *) * (strlen_tab(env) + 1));
	int nb = 0;

	while (env[nb] != NULL) {
		to_ret[nb] = my_strcpy(env[nb]);
		nb++;
	}
	to_ret[nb] = NULL;
	return to_ret;
}

void no_null_env(t_env *my_env, char **env)
{
	my_env->env = cpy_env(env);
	my_env->pwd	= malloc(sizeof(char) * 30);
	getcwd(my_env->pwd, 30);
	my_env->is_empty = 1;
}

void deal_with_env(t_env *my_env, char **env)
{
	if (env[0] == NULL)
		null_env(my_env);
	else
		no_null_env(my_env, env);
	my_env->oldpwd = my_strcpy(my_env->pwd);
}

void put_prompt(t_env *env)
{
	char *to_print = my_strcat(env->pwd, ": ");

	my_putstr(to_print);
}
