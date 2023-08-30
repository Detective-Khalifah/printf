#include "main.h"

/**
 * process_unsigned_int - process the unsigned int specifier
 * @args: va_list with arguments
 *
 * Return: number of characters printed (excluding the null byte)
 */
int process_unsigned_int(va_list args)
{
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);

	count += idigit((long)num, 10);

	return (count);
}

/**
 * process_octal - process the octal specifier
 * @args: va_list with arguments
 * @flags: for non-custom conversion specifiers
 *
 * Return: number of characters printed (excluding the null byte)
 */
int process_octal(va_list args, char flags)
{
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);

	if (flags == '#')
	{
		count += _putchar('0');
	}

	count += idigit((long)num, 8);

	return (count);
}

/**
 * process_hex - process the hexadecimal character specifier
 * @args: va_list with arguments
 * @flags: for non-custom conversion specifiers
 *
 * Return: number of characters printed (excluding the null byte)
 */
int process_hex(va_list args, char flags)
{
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);

	if (flags == '#')
	{
		count += _putchar('0');
		count += _putchar('x');
	}

	count += idigit((long)num, 16);

	return (count);
}

/**
 * process_binary - process the binary character specifier
 * @args: va_list with arguments
 *
 * Return: number of characters printed (excluding the null byte)
 */
int process_binary(va_list args)
{
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);

	count += idigit((long)num, 2);

	return (count);
}

/**
 * process_unknown - process other character specifiers
 * @specifier: the character
 *
 * Return: number of characters printed (excluding the null byte)
 */
int process_unknown(char specifier)
{
	int count = 0;

	icharacter('%');
	icharacter(specifier);
	count += 2;

	return (count);
}
