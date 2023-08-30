#include "main.h"

/**
 * idigit - writes numbers to stdout
 * @n: the number to print
 * @base: num system of the number to print (eg base 2, 10, 16)

 */
void idigit(long n, int base)
{
	char *symbols = "0123456789abcdef";
	char buffer[32];
	int index = 0, i = index -1;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}

	if (n == 0)
	{
		buffer[index] = symbols[0];
		index++;
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
		}
	}
}

