#include "main.h"
#include <string.h>

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

	if (specifier == 'c')
	{
		count += icharacter(va_arg(args, int));
	}
	else if (specifier == 's')
	{
		char *str = va_arg(args, char *);
		if (str == NULL)
			str = "(null)";
		istring(str);
		count += strlen(str);
	}
	else if (specifier == '%')
	{
		count += icharacter('%');
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		int num = va_arg(args, int);
        if (num < 0)
        {
            count += icharacter('-');
            num = -num;
        }
        count += idigit((long)num, 10);
	}
	else if (specifier == 'b')
    {
        unsigned int num = va_arg(args, unsigned int);
        count += idigit((long)num, 2);
    }
	else if (specifier == 'x')
	{
		idigit((long) va_arg(args, unsigned int), 16);
	}
	else
	{
		icharacter('%');
		icharacter(specifier);
		count +=2;
	}

	return (count);
}

