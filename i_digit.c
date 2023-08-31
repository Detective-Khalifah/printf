#include "main.h"

/**
 * idigit - writes numbers to stdout
 * @n: the number to print
 * @base: num system of the number to print (eg base 2, 10, 16)
 *
 * Return: number of characters printed (excluding the null byte)
 */
int idigit(long n, int base)
{
	char *symbols = "0123456789ABCDEF";
	char buffer[32];
	int index = 0, i = index - 1;
	int count = 0; /* Initialize character count */

	if (n < 0)
	{
		icharacter('-');
		n = -n;
		count++;
	}

	if (n == 0)
	{
		buffer[index] = symbols[0];
		index++;
		count++;
	}
	else
	{
		while (n > 0)
		{
			buffer[index] = symbols[n % base];
			n /= base;
			index++;
		}

		for (; i >= 0; i--)
		{
			icharacter(buffer[i]);
			count++;
		}
	}

	return (count);
}

/**
 * idigit_length - writes numbers to stdout with specified field width
 * @n: the number to print
 * @base: num system of the number to print (eg base 2, 10, 16)
 * @width: field width
 *
 * Return: number of characters printed (excluding the null byte)
 */
int idigit_length(long n, int base, int width)
{
	char *symbols = "0123456789ABCDEF";
	char buffer[32];
	int index = 0, i = index - 1, padding;
	int count = 0; /* Initialize character count */

	if (n < 0)
	{
		icharacter('-');
		n = -n;
		count++;
	}

	if (n == 0)
	{
		buffer[index] = symbols[0];
		index++;
		count++;
	}
	else
	{
		while (n > 0)
		{
			buffer[index] = symbols[n % base];
			n /= base;
			index++;
		}

        /* Calculate the number of padding spaces needed */
        padding = width - index;
        while (padding > 0)
        {
        	icharacter(' ');
        	count++;
        	padding--;
        }

		for (; i >= 0; i--)
		{
			icharacter(buffer[i]);
			count++;
		}
	}

	return (count);
}

