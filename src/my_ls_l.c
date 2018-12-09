/*
** EPITECH PROJECT, 2017
** yassine.benmessahel@epitech.eu
** File description:
** my_ls_l
*/

#include "../include/my.h"
#include "../include/lib.h"

int my_ls_file(char *filepath)
{
	struct dirent *dir;
	DIR *d;
	int total = my_total_count(filepath);
	char *filename;
	char *result;

	d = opendir(filepath);
	if (d == NULL)
		exit(84);
	my_printf("total %d\n", total);
	while ((dir = readdir(d)) != NULL) {
		if (*dir->d_name != '.') {
			filename = my_strdup(dir->d_name);
			result = my_strcat(my_strdup(filepath), filename);
			my_ls_l(result);
		}
	}
	closedir(d);
	return (0);
}

int my_ls_l(char *filename)
{
	struct stat *sb;
	struct passwd *uid;
	struct group *gid;

	sb = malloc(sizeof(struct stat));
	stat(filename, sb);
	uid = getpwuid(sb->st_uid);
	my_print_mode(filename);
	my_print_chmode(filename);
	my_putchar('.');
	my_printf(" %d", sb->st_nlink);
	my_printf(" %s", uid->pw_name);
	gid = getgrgid(sb->st_gid);
	my_printf(" %s %d ", gid->gr_name, sb->st_size);
	my_date(ctime(&sb->st_ctime));
	my_ls_dir_color(my_ls_path_cut(filename));
	my_putstr("\033[22;37m\n");
	return (0);
}

int my_total_count(char *filepath)
{
	struct stat *sb;
	struct dirent *dir;
	DIR *d;
	char *file;
	char *result;
	int total = 0;

	d = opendir(filepath);
	while ((dir = readdir(d)) != NULL) {
		if (*dir->d_name != '.') {
			file = dir->d_name;
			sb = malloc(sizeof(struct stat));
			result = my_strcat(my_strdup(filepath), file);
			stat(result, sb);
			total = total + (sb->st_blocks / 2);
		}
	}
	closedir(d);
	return (total);
}

void my_print_mode(char *filepath)
{
	struct stat *sb;

	sb = malloc(sizeof(struct stat));
	stat(filepath, sb);
	if (S_ISREG(sb->st_mode))
		my_putstr("-");
	if (S_ISDIR(sb->st_mode))
		my_putstr("d");
	if (S_ISBLK(sb->st_mode))
		my_putstr("b");
	if (S_ISCHR(sb->st_mode))
		my_putstr("c");
	if (S_ISFIFO(sb->st_mode))
		my_putstr("p");
	if (S_ISLNK(sb->st_mode))
		my_putstr("l");
	if (S_ISSOCK(sb->st_mode))
		my_putstr("s");
}

int my_print_chmode(char *filepath)
{
	struct stat *sb;
	int compare[11] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH, 0};
	char c[4] = "rwx";
	int nb = 0;
	int nbtwo = 0;

	sb = malloc(sizeof(struct stat));
	stat(filepath, sb);
	while (compare[nb] != 0) {
		if (compare[nb] & sb->st_mode ? my_putchar(c[nbtwo]) : my_putstr("-")){}
		nbtwo = nbtwo + 1;
		nb = nb + 1;
		if (nbtwo == 3)
			nbtwo = 0;
	}
	return (0);
}
