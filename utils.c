#include "shell.h"

/**
 * _strdup - Duplicate a string
 * @str: The string to duplicate
 *
 * Return: A pointer to the duplicated string, or NULL if failed
 */
char *_strdup(const char *str)
{
	char *dup;
	size_t len = 0, i;

	if (!str)
		return (NULL);

	while (str[len])
		len++;

	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[i] = '\0';

	return (dup);
}

/**
 * _strlen - Return the length of a string
 * @s: The string
 *
 * Return: The length
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s && s[len])
		len++;

	return (len);
}
