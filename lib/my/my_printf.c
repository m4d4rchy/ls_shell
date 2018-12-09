/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
**
*/
#include "lib.h"

int my_printf(char const *str, ...)
{
	int number;
	int i = 0;
	va_list ap;
	int p = 0;

	va_start(ap, str);
	while (str[i] != '\0') {
		if (str[i] == '%') {
			i = my_print_basic(str, ap, i, p);
			i = prints(str, ap, i);
			if (str[i] == '%' && str[i + 1] == 'o'
			    && (str[i - 1] != '%' || p == 1)) {
				number = va_arg(ap, int);
				my_print_octal(number);
				p = 0;
				i = i + 2;
			}
			else if (str[i] == '%' && str[i + 1] == 'b'
				 && (str[i - 1] != '%' || p == 1)) {
				number = va_arg(ap, int);
				my_print_bin(number);
				p = 0;
				i = i + 2;
			}
			else if (str[i] == '%' && (str[i + 1] == 'x' || str[i + 1] == 'X')
				 && (str[i - 1] != '%' || p == 1)) {
				number = va_arg(ap, int);
				if (str[i + 1] == 'X')
					my_print_hexa(number, 32);
				else
					my_print_hexa(number, 0);
				p = 0;
				i = i + 2;
			}
			else if (str[i] == '%' && str[i + 1] == '%') {
				my_putchar(str[i]);
				p = 1;
				i = i + 2;
			}
		}
		else {
			my_putchar(str[i]);
			i = i + 1;
		}

	}
	va_end(ap);
	return (0);
}

int prints(char const *str, va_list ap, int i)
{
	char *string;
	int nb = 0;
	int count = 0;

	if (str[i + 1] == 'S') {
		string = va_arg(ap, char*);
		while (string[count] != '\0') {
			if (string[count] > 1 && string[count] < 32) {
				nb = string[count];
				my_putchar('\\');
				my_putchar('0');
				if (nb < 9) {
					my_putchar('0');
				}
				my_print_octal(nb);
			}
			else {
				my_putchar(string[count]);
			}
			count = count + 1;
		}
		i = i + 2;
	}
	return (i);
}

int my_print_basic(char const *str, va_list ap, int i, int p)
{
	char *string;
	char character;
	int number;
	long lon;

	if (str[i] == '%' &&  str[i + 1] == 'c' && (str[i - 1] != '%' || p == 1)) {
		character = (char)va_arg(ap, int);
		my_putchar(character);
		p = 0;
		i = i + 2;
	}
	if (str[i] == '%' && str[i + 1] == 'l' && (str[i - 1] != '%' || p == 1)) {
		lon = va_arg(ap, long);
		my_put_long(lon);
		p = 0;
		i = i + 2;
	}
	if (str[i] == '%' && str[i + 1] == 's' && (str[i - 1] != '%' || p == 1)) {
		string = va_arg(ap, char*);
		my_print_null(string);
		my_putstr(string);
		p = 0;
		i = i + 2;
	}
	if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i')
	    && (str[i - 1] != '%' || p == 1)) {
		number = va_arg(ap, int);
		my_put_nbr(number);
		p = 0;
		i = i + 2;
	}
	return (i);
}

int my_print_null(char *str)
{
	if (str == NULL)
		my_putstr("(null)");
	return (0);
}
