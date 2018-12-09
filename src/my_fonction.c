/*
** EPITECH PROJECT, 2017
** yassine.benmessahel@epitech.eu
** File description:
** my_ls_l
*/

#include "../include/my.h"
#include "../include/lib.h"

char *my_ls_path_cut(char *filename)
{
	char *result = malloc(sizeof (char) * 10000);
	int nb2 = 0;
	int nb = 0;
	int cpy = 0;

	while (filename[nb] != '\0') {
		if (filename[nb] == '/') {
			cpy = 1;
			nb = nb + 1;
		}
		if (cpy == 1) {
			result[nb2] = filename[nb];
			nb2 = nb2 + 1;
		}
		nb = nb + 1;
	}
	result[nb2 + 1] = '\0';
	return (result);
}

int my_ls_dir_color(char *filename)
{
	struct stat *sb;

	sb = malloc(sizeof(struct stat));
	stat(filename, sb);
	if (S_ISDIR(sb->st_mode)) {
		my_printf("\033[22;34m%s", filename);
	}
	else if (!S_ISDIR(sb->st_mode) && S_IXGRP & sb->st_mode)
		my_printf("\033[01;32m%s", filename);
	else
		my_printf("\033[22;37m%s", filename);
	return (0);
}

void my_date(char *date)
{
	char *result = malloc(sizeof(char) * 1000);
	int nb = 4;
	int nbtwo = 0;

	while (nb != 16) {
		result[nbtwo] = date[nb];
		nb = nb + 1;
		nbtwo = nbtwo + 1;
	}
	result[nbtwo] = ' ';
	result[nbtwo + 1] = '\0';
	my_putstr(result);
}
