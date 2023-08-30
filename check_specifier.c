#include "main.h"
#include <string.h>

int process_specifier(va_list args, char specifier);
int process_string_escape(va_list args);
int process_unknown(char specifier);
int process_hex(va_list args);
int process_octal(va_list args);
int process_binary(va_list args);
int process_unsigned_int(va_list args);
int process_int(va_list args);
int process_string(va_list args);
int process_char(va_list args);

/**
 * check_specifier - return a pointer with the matching format
 * @args: va_list with arguments
 * @specifier: format specifier
 *
 * Return: number of characters printed (excluding the null byte)
 */
int check_specifier(va_list args, char specifier)
{
	int count = 0;

	if (specifier == '%')
	{
		count += icharacter('%');
	}
	else
	{
		count += process_specifier(args, specifier);
	}

	return (count);
}


/**
 * process_specifier - process the format specifier and print accordingly
 * @args: va_list with arguments
 * @specifier: format specifier
 * @flags: for non-custom conversion specifiers
 *
 * Return: number of characters printed (excluding the null byte)
 */
int process_specifier(va_list args, char specifier, char flags)
{
	switch (specifier)
	{
		case 'c':
			return (process_char(args));
		case 's':
			return (process_string(args));
		case 'd':
		case 'i':
			return (process_int(args, flags));
		case 'u':
			return (process_unsigned_int(args));
		case 'o':
			return (process_octal(args, flags));
		case 'x':
		case 'X':
			return (process_hex(args, flags));
		case 'b':
			return (process_binary(args));
		case 'S':
			return (process_string_escape(args));
		case 'p':
			return (process_pointer(args));
		default:
			return (process_unknown(specifier));
		}
}

/**
 * process_char - process the character specifier
 * @args: va_list with arguments
 *
 * Return: number of characters printed (excluding the null byte)
 */
int process_char(va_list args)
{
	int count = 0;
	int ch = va_arg(args, int);

	count += icharacter(ch);

	return (count);
}

/**
 * process_string - process the string specifier
 * @args: va_list with arguments
 *
 * Return: number of characters printed (excluding the null byte)
 */
int process_string(va_list args)
{
	int count = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	istring(str);
	count += strlen(str);

	return (count);
}

/**
 * process_int - process the iny specifier
 * @args: va_list with arguments
 * @flags: for non-custom conversion specifiers
 *
 * Return: number of characters printed (excluding the null byte)
 */
int process_int(va_list args, char flags)
{
	int count = 0;
	int num = va_arg(args, int);

	if (num < 0)
	{
		count += icharacter('-');
		num = -num;
	}
	else if (num >= 0)
	{
		if (flags == '+')
		{
			count += icharacter('+');
		}
		else if (flags == ' ')
		{
			count += icharacter(' ');
		}
	}

	count += idigit((long)num, 10);

	return (count);
}

