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
	int count = 0;
	va_list arg;

	va_start(arg, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			check_specifier(arg, *(++format));
			break;
		}
		else
		{
			icharacter(*format);
		}

		format++;
	}

	va_end(arg);


	return (count);
}

