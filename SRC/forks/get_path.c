/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** get_cmd
*/

#include "include.h"
#include "ms2.h"
#include "struct.h"

int count_sep_path(char *path)
{
	int path_nb = 0;
	int nb = 0;

	while (path[path_nb] != '=')
	path_nb++;
	while (path[path_nb] != '\0') {
		if (path[path_nb] == ':')
		nb++;
		path_nb++;
	}
	nb = nb + 2;
	return nb;
}

int skip_to_equal(char *str)
{
	int nb = 0;

	while (str[nb] != '=')
		nb++;
	return nb;
}

char **cpy_path(char *path)
{
char **out = malloc(sizeof(char *) * (count_sep_path(path) + 10));
int out_nb = 0;
int nb_nb = 0;
int path_nb = skip_to_equal(path);

out[0] = malloc(sizeof(char) * (my_strlen(path) + 1));
while (path[path_nb] != '\0') {
	if (path[path_nb] == ':') {
		out[out_nb][nb_nb] = '/';
		out[out_nb][nb_nb] = '\0';
		out_nb++;
		out[out_nb] = malloc(sizeof(char) * (my_strlen(path) + 1));
		nb_nb = 0;
		path_nb++;
	}
	out[out_nb][nb_nb] = path[path_nb];
	nb_nb++;
	path_nb++;
}
out[out_nb] = NULL;
return out;
}

char *my_strcat_path(char *dest, char *src)
{
	char *out = malloc(sizeof(char) * (my_strlen(dest)+my_strlen(src) + 2));
	int dest_nb = 0;
	int out_nb = 0;
	int src_nb = 0;

	while (dest[dest_nb] != '\0') {
		out[out_nb] = dest[dest_nb];
		out_nb++;
		dest_nb++;
	}
	out[out_nb] = '/';
	out_nb++;
	while (src[src_nb] != '\0') {
		out[out_nb] = src[src_nb];
		src_nb++;
		out_nb++;
	}
	out[out_nb] = '\0';
	return out;
}

char **get_path(char **env)
{
	int env_nb = 0;
	char **out = malloc(sizeof(char *) * 200);
	int line;

	while (env[env_nb] != NULL) {
		if (env[env_nb][0] == 'P'
		&& env[env_nb][1] == 'A' && env[env_nb][2] == 'T'
		&& env[env_nb][3] == 'H') {
			line = env_nb;
			out = cpy_path(env[line]);
			return out;
		}
		env_nb++;
	}
	return NULL;
}
