/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
**
*/
#include "lib.h"

int my_print_octal(int number)
{
	char *result = malloc(sizeof(int) * number);
	int nb = number / 8;
	int i = 1;

	result[0] = (number % 8) + 48;
	while (nb > 8) {
		result[i] = (nb % 8) + 48;
		nb = nb / 8;
		i = i + 1;

	}
	if (nb % 8 != 0)
		result[i] = (nb % 8) + 48;
	result[i + 1] = '\0';
	result = my_revstr(result);
	my_putstr(result);
	return (my_getnbr(result));
}

int my_print_bin(int number)
{
	char *result = malloc(sizeof(int) * number);
	int nb = number / 2;
	int i = 1;

	result[0] = (number % 2) + 48;
	while (nb >= 2) {
		result[i] = (nb % 2) + 48;
		nb = nb / 2;
		i = i + 1;

	}
	if (nb % 2 != 0)
		result[i] = (nb % 2) + 48;
	result[i + 1] = '\0';
	result = my_revstr(result);
	my_putstr(result);
	return (my_getnbr(result));
}

int my_print_hexa(int number, int capi)
{
	char *result = malloc(sizeof(int) * number);
	int nb = 0;
	int i = 1;
	int neg = 0;

	if (number < 0) {
		neg = 1;
		number = number * (-1);
	}
	nb = number / 16;
	result[0] = (number % 16) + 48;
	while (nb > 16) {
		result[i] = (nb % 16) + 48;
		nb = nb / 16;
		i = i + 1;

	}
	if (nb != 0)
		result[i] = nb + 48;
	if (neg == 1) {
		i = i + 1;
		result[i] = '-';
	}
	i = i + 1;
	result[i] = '\0';
	result = my_revstr(result);
	i = 0;
	while (result[i] != '\0') {
		if (result[i] > '9')
			result[i] = (result[i] + 39) - capi;
		i = i + 1;
	}
	my_putstr(result);
	return (0);
}
