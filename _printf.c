#include "main.h"

int print_format(const char *format, va_list args);

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
	count = print_format(format, arg);
	va_end(arg);

	return (count);
}

/**
 * print_format - processes the format string and prints the output
 * @format: the format. A string -- character array with specifiers.
 * @args: va_list with arguments
 *
 * Return: number of characters printed (excluding the null byte)
 */
int print_format(const char *format, va_list args)
{
	int count = 0, chars_written;
	char buffer[1024]; /* Local buffer to accumulate characters */
	int buffer_index = 0; /* Index for the local buffer */

	while (*format != '\0')
	{
		if (buffer_index >= 1023)
		{
			write(1, buffer, buffer_index);
			buffer_index = 0; /* Reset buffer index */
		}

		if (*format == '%')
		{
			format++; /* Move past '%' */
			if (*format == '\0')
				break; /* Handle cases where '%' is at the end of the string */

			chars_written = check_specifier(args, *format);

			if (chars_written > 0)
			{
				buffer_index += chars_written;
				count += chars_written;
			}
		}
		else
		{
			buffer[buffer_index++] = *format; /* Accumulate character in buffer */
			count++;
		}

		format++;
	}

	/* Print remaining characters in the buffer */
	if (buffer_index > 0)
	{
		write(1, buffer, buffer_index);
	}

	return (count);
}

