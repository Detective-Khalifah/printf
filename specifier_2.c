#include "main.h"

/**
 * process_string_escape - process the string specifier with escape characters
 * @args: va_list with arguments
 *
 * Return: number of characters printed (excluding the null byte)
 */
int process_string_escape(va_list args)
{
	int count = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < ' ' || str[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += idigit((long)str[i], 16);
		}
		else
		{
			count += _putchar(str[i]);
		}
	}

	return (count);
}

