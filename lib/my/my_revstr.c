/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** 
*/

void my_putchar(char c);
int my_strlen(char const *str);
char *my_revstr(char *str)
{
	int len = my_strlen(str) - 1;
	int count = 0;
	char a;

	while (count < len) {
		a = str[len];
		str[len] = str[count];
		str[count] = a;
		count = count + 1;
		len = len - 1;
	}
	return (str);
}
