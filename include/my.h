/*
** EPITECH PROJECT, 2017
** yassine.benmessahel@epitech.eu
** File description:
** my.h
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
#define _BSD_SOURCE


int	my_ls_dir(char *filepath, int option);
int	my_option_check(int argc, char **argv);
int	my_ls_l(char *filename);
int	my_ls_file(char *filepath);
int	my_total_count(char *filepath);
void	my_print_mode(char *filepath);
int	my_print_chmode(char *filepath);
int	my_ls_dir_color(char *filename);
char	*my_ls_path_cut(char *filename);
void	my_date(char *date);
