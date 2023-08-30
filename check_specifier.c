#include "main.h"

/**
 * check_specifier - return a pointer with the matching format
 * @c: format specifier
 * Return: pointer a pointer to a function
 */
void check_specifier(va_list args, char specifier)
{

	if (specifier == 'c')
	{
		_putchar(va_arg(args, int));
	}
	else if (specifier == 's')
	{
		istring(va_arg(args, char*));
	}
	else if (specifier == 'd')
	{
		idigit((long) va_arg(args, int), 10);
	}
	else if (specifier == 'x')
	{
		idigit((long) va_arg(args, unsigned int), 16);
	}

	/* return (NULL); */
}

