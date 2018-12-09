/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
**
*/

int my_check_sign(int nb, int sign);
int my_getnbr(char const *str)
{
	int count = 0;
	int count2 = 0;
	int sign = 0;
	int nb = 0;

	while (str[count] != '\0') {
		while (str[count] >= '0' && str[count] <= '9' && count2 == 0) {
			if (str[count + 1] < '0'|| str[count + 1] > '9')
				count2 = 1;
			if (str[count - 1] == '-' )
				sign = -1;
			nb = (nb + str[count] - 48) * 10;
			count = count + 1;
		}
		if (nb >= 214748364)
			nb = 0;
		count = count + 1;
	}
	nb = my_check_sign(nb, sign);
	return (nb);
}

int my_check_sign(int nb, int sign)
{
	nb = nb / 10;
	if (sign == -1) {
		nb = nb * sign;
	}
	return (nb);
}
