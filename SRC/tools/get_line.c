/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** get_line
*/

#include "struct.h"
#include "ms2.h"
#include "include.h"
#include "tools.h"

char *check_line(char *str)
{
	static int str_nb;
	char *save = malloc(sizeof(char) * (my_strlen(str) + 1));
	int save_nb = 0;
	char *cpy = my_strcpy(str);

	while (cpy[str_nb] != '\0') {
		if (cpy[str_nb] == '\n') {
			save[save_nb] = '\0';
			str_nb++;
			return (save);
		}
		save[save_nb] = cpy[str_nb];
		save_nb++;
		str_nb++;
	}
	str_nb++;
	save[save_nb] = '\0';
	free(cpy);
	return (save);
}

int check_n(char *str)
{
	static int str_nb;
	int cpy_str_nb = str_nb;
	char *cpy = my_strcpy(str);

	str_nb++;
	while ((my_strlen(cpy) > cpy_str_nb) && (cpy[cpy_str_nb] != '\0')) {
		if (cpy[cpy_str_nb] == '\n') {
			return 1;
		}
		cpy_str_nb++;
	}
	free(cpy);
	return 0;
}

char *get_save(char *save)
{
	save = malloc(sizeof(char) * 1);
	save[0] = '\0';
	return save;
}

char *get_next_line(int fd)
{
	char *str = malloc(sizeof(char) * READ_SIZE + 1);
	static char *save = NULL;
	static int str_nb = 0;
	int i = 0;

	if (save == NULL)
	save = get_save(save);
	if (fd == -1)
		return save;
	while ((i = read(fd, str, READ_SIZE)) > 0) {
		str[i] = '\0';
		save = my_strcat(save, str);
		if (check_n(save) == 1) {
			str_nb++;
			return (check_line(save));
		}
	}
	if (i != 0) {
		return save;
	}
	return NULL;
}

void break_it(void)
{
	int i = 0;

	while (i != 2)
		i++;
}
