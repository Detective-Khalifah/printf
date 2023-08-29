#include "main.h"

/**
 * check_specifier - return a pointer with the matching format
 * @c: format specifier
 * Return: pointer a pointer to a function
 */
int (*check_specifier(const char *c))(va_list args)
{
	int i;

	args_t func_cs[] = {
		{"c", print_character},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_decimal},
		{"i", print_integer},
		{NULL, NULL}};

	i = 0;

	while (func_cs[i].ch)
	{
		if (*(func_cs[i].ch) == *c)
		{
			return (func_cs[i].f);
		}

		i++;
	}

	return (NULL);
}

