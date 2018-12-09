/*
** EPITECH PROJECT, 2017
** yassine.benmessahel@epitech.eu
** File description:
** main
*/

#include "../include/my.h"
#include "../include/lib.h"

int main(int argc, char **argv)
{
	if (argc == 1)
		my_ls_dir(".", 0);
	else
		my_option_check(argc, argv);
	return (0);
}

int my_option_check(int argc, char **argv)
{
	int nb = 1;

	if (argv[1][0] == '-') {
		while (argv[1][nb] != '\0') {
			if (argc == 2) {
				if (argv[1][nb] == 'l') {
					my_ls_file("./");
				}
				else if (argv[1][nb] == 'a') {
					my_ls_dir(".", 1);
				}
			}
			if (argc > 2) {
				if (argv[1][nb] == 'a')
					my_ls_dir(argv[2], 1);
				if (argv[1][nb] == 'l') {
					my_ls_file(argv[2]);
				}
			}
			nb = nb + 1;
		}
	}
	else if (argc == 2) {
		my_ls_dir(argv[1], 0);
	}
	return (0);
}

int my_ls_dir(char *filepath, int option)
{
	struct dirent *dir;
	DIR *d;

	d = opendir(filepath);
	if (d == NULL)
		exit(84);
	while ((dir = readdir(d)) != NULL) {
		if (*dir->d_name != '.' && option == 0) {
			my_ls_dir_color(dir->d_name);
			my_putstr(" ");
		}
		else if (option == 1) {
			my_ls_dir_color(dir->d_name);
			my_putstr(" ");
		}
	}
	closedir(d);
	return (0);
}
