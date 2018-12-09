/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
**
*/

void my_putchar(char c);
int my_strlen(char const *str)
{
	int nb = 0;

	while (str[nb] != '\0') {
		nb = nb + 1;
	}
	return (nb);
}
