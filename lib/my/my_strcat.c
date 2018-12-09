/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** 
*/

int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src)
{
	int	len = my_strlen(dest);
	int	count = 0;

	while (src[count] != '\0') {
		dest[len] = src[count];
		count = count + 1;
		len = len + 1;
	}
	dest[len] = '\0';
	return (dest);
}
