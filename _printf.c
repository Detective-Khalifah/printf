#include "main.h"

/**
 * _printf - clone printf function; writes output to standard output stream
 * according to some (specified) format.
 * @format: the format. A string -- character array with specifiers.
 *
 * Return: number of printed characters.
 */
int _printf(const char *format, ...)
{
	int i, count = 0, value, (*func)(va_list);
	va_list arg;

	va_start(arg, format);
	i = 0;

	while (*(format + i))
	{
		if (format[i] != '%')
		{
			value = _putchar(format[i]);
			count += value;
			i++;
		}
		if (format[i] == '%')
		{
			func = check_specifier(&format[i + 1]);
			if (func != NULL)
			{
				value = func(arg);
				count += value;
				i += 2;
			}
			else
			{
				value = _putchar(format[i]);
				count += value;
				i++;
			}
		}
	}

	va_end(arg);

	return (count);
}

