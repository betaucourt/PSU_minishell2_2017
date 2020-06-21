/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** main
*/

#include "ms2.h"
#include "include.h"
#include "struct.h"
#include "tools.h"

char *my_revstr(char *str)
{
	int i = 0;
	int j = my_strlen	(str) - 1;
	char value;

	while (i < j) {
		value = str[i];
		str[i] = str[j];
		str[j] = value;
		i++;
		j--;
	}
	return (str);
}

void my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}

int my_atoi(char *str)
{
	int nbr = 0;
	int i = 0;

	while (str[i] == ' ') {
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9') {
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return nbr;
}

void my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_put_nbr(int nb)
{
	int	mod;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 0) {
		if (nb >= 10){
			mod = (nb % 10);
			nb = (nb - mod) / 10;
		my_put_nbr(nb);
		my_putchar(48 + mod);
		}
		else
		my_putchar(48 + nb % 10);
	}
	return 0;
}
