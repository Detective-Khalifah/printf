#include <unistd.h>

/**
 * _putchar - writes the character @c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * icharacter - writes the character @ch to stdout
 * @ch: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int icharacter(int ch)
{
	return (write(1, &ch, 1));
}

