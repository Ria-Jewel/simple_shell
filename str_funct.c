#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 * @s: The string to be measured.
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;

	return (i);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination buffer.
 * @src: The source string to be appended.
 * Return: A pointer to the destination buffer.
 */
char *_strcat(char *dest, char *src)
{
	char *temp = dest;

	while (*dest)
		dest++;

	*dest++ = '/';

	while (*src)
		*dest++ = *src++;

	return (temp);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 * Return: 0 if strings are not equal, 1 if equal.
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}

	return (1);
}

/**
 * _strcpy - Copies a string from src to dest.
 * @dest: The destination buffer.
 * @src: The source string to be copied.
 * Return: A pointer to the destination buffer.
 */
char *_strcpy(char *dest, char *src)
{
	char *temp = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';

	return (temp);
}

/**
 * _atoi - Converts a string to an integer.
 * @str: The string to be converted.
 * Return: The converted integer value.
 */
int _atoi(char *str)
{
	unsigned int ret = 0;
	int i = 0, sign = 1, f = 0, temp;

	for (; str[i] != '\0' && f != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			f = 1;
			ret *= 10;
			ret += (str[i] - '0');
		}
		else if (f == 1)
			f = 2;
	}

	if (sign == -1)
		temp = -ret;
	else
		temp = ret;

	return (temp);
}

