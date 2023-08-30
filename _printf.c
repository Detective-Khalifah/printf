#include "main.h"

/**
 * _printf - clone printf function; writes output to standard output stream
 * according to some (specified) format.
 * @format: the format. A string -- character array with specifiers.
 *
 * Return: number of printed characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int count = 0; /* Initialize character count */
	va_list arg;

	va_start(arg, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++; /* Move past '%' */
			if (*format == '\0')
				break; /* Handle cases where '%' is at the end of the string */

			count += check_specifier(arg, *format);
		}
		else
		{
			count += icharacter(*format); /* Print regular characters */
		}

		format++;
	}

	va_end(arg);


	return (count);
}

