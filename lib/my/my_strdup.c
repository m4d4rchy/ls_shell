/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** 
*/

#include <stdlib.h>
int my_strlen(char const *str);
char *my_strdup(char const *src)
{
	int count = 0;
	int lenght = my_strlen(src);
	char *dest = malloc(sizeof (char) * lenght);

	while (src[count] != '\0') {
		dest[count] = src[count];
		count = count + 1;
	}
	dest[count] = '\0';
	return (dest);
}
