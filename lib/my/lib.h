/*
** EPITECH PROJECT, 2017
** Makefiles
** File description:
** 
*/
#include <stdlib.h>
#include <stdarg.h>

#ifndef LIB_H_
#define LIB_H_

char	*concat_params(int argc, char **argv);
int	my_argvlen(int argc, char **argv);
int	my_compute_factorial_it(int nb);
int	my_compute_power_it(int nb, int p);
int	my_square_root(int nb);
int	my_print_alpha(void);
int	my_print_digits(void);
void	my_print_params(int argc, char **argv);
int	my_print_revalpha(void);
void	my_rev_params(int argc, char **argv);
char	*my_revstr(char *str);
int	my_show_word_array(char * const *tab);
char	*my_strcapitalize(char *str);
char	*my_strcat(char *dest, char const *src);
char	*my_strcpy(char *dest, char const *src);
char	*my_strdup(char const *src);
char	*my_strlowcase(char *str);
char	*my_strncat(char *dest, char const *src, int nb);
char	*my_strncpy(char *dest, char const *src, int n);
char	*my_strstr(char const *str, char const *to_find);
char	**my_str_to_word_array(char const *str);
char	*my_strupcase(char *str);
int	my_putchar(char c);
int	my_isneg(int nb);
int	my_printf(char const *str, ...);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char const *str);
int	my_strlen(char const *str);
int	my_getnbr(char const *str);
int	my_print_hexa(int number, int capi);
int	my_print(char const *str, int i);
int	my_print_octal(int number);
long	my_put_long(long nb);
int	my_print_basic(char const *str, va_list ap, int i, int p);
int	prints(char const *str, va_list ap, int i);
int	my_print_bin(int number);
int	my_print_null(char *str);

#endif
