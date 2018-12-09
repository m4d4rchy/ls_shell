/*
** EPITECH PROJECT, 2017
** my_print_digits
** File description:
**
*/

int my_put_nbr(int nb);
void my_putchar(char c);

int my_print_digits(void)
{
	int nb = 0;

	while (nb <= 9) {
		my_put_nbr(nb);
		nb = nb + 1;
	}
	return (0);
}
