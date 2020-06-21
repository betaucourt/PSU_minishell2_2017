/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** main
*/

#include "ms2.h"
#include "include.h"
#include "struct.h"
#include "tools.h"

char *my_strcat(char *dest, char *src)
{
char *out = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
int dest_nb = 0;
int out_nb = 0;
int src_nb = 0;

while (dest[dest_nb] != '\0') {
	out[out_nb] = dest[dest_nb];
	out_nb++;
	dest_nb++;
}
while (src[src_nb] != '\0') {
	out[out_nb] = src[src_nb];
	src_nb++;
	out_nb++;
}
out[out_nb] = '\0';
return out;
}

char **cpy_tab(char **tab)
{
	char **to_ret = malloc(sizeof(char *) * (strlen_tab(tab) + 1));
	int tab_nb = 0;

	while (tab[tab_nb] != NULL) {
		to_ret[tab_nb] = my_strcpy(tab[tab_nb]);
		tab_nb++;
	}
	to_ret[tab_nb] = NULL;
	return to_ret;
}

void my_putstr_r(char *str)
{
	write(2, str, my_strlen(str));
}
