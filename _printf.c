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

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			_putchar(va_arg(arg, int));
			break;
		}
		else
		{
			_putchar(*format);
		}

		format++;
	}

	va_end(arg);


	return (count);
}

