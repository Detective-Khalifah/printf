#include "main.h"

/**
 * process_string_escape - process the string specifier with escape characters
 * @args: va_list with arguments
 *
 * Return: number of characters printed (excluding the null byte)
 */
int process_string_escape(va_list args)
{
	int count = 0, i = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < ' ' || str[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			if (str[i] < 16)
				count += _putchar('0');
			count += idigit((long)str[i], 16);
		}
		else
		{
			count += _putchar(str[i]);
		}
	}

	return (count);
}

#include "main.h"

/**
 * process_pointer - process the pointer specifier
 * @args: va_list with arguments
 *
 * Return: number of characters printed (excluding the null byte)
 */
int process_pointer(va_list args)
{
	int count = 0;
	void *ptr = va_arg(args, void *);

	count += _putchar('0');
	count += _putchar('x');
	count += idigit((unsigned long)ptr, 16);

	return (count);
}

