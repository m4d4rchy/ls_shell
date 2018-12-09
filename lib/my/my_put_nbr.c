/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** 
*/

void	my_putchar(char c);
int	my_put_nbr(int nb)
{
	int number = 0;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	if (nb > 9) {
		my_put_nbr(nb / 10);
		number = nb % 10;
		my_putchar(number + 48);
	} else {
		my_putchar(nb + 48);
	}
	return (nb);
}
