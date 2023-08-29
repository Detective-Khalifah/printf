#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_character - prints a character
 * @arg: argument list
 * Return: length of the character(s)
 */
int print_character(va_list arg)
{
	char c;
	int count;

	c = va_arg(arg, int);

	count = _putchar(c);
	return (count);
}

/**
 * print_string - prints a string -- character array
 * @arg: argument list
 * Return: length of the string
 */
int print_string(va_list arg)
{
	char *string0, *string1;
	int count = 0, i, value = 0;

	string0 = va_arg(arg, char *);

	if (string0 == NULL)
	{
		va_list arg2;

		va_copy(arg2, arg);

		string1 = va_arg(arg2, char *);
		string1 = "(null)";

		for (i = 0; string1[i]; i++)
		{
			value = _putchar(string1[i]);
			count += value;
		}

		va_end(arg2);

		return (count);
	}

	i = 0;

	while (*(string0 + i))
	{
		count += _putchar(string0[i]);
		i++;
	}

	return (count);

}

/**
 * print_percent - print percentage symbol
 * @arg: argument list
 * Return: length of the argument
 */
int print_percent(va_list arg)
{
	va_list percent;
	int count = 0;
	char c;

	va_copy(percent, arg);

	c = va_arg(percent, int);
	c = '%';

	count += _putchar(c);
	va_end(percent);

	return (count);
}

/**
 * print_decimal - prints decimal
 * @args: argument list
 * Return: length of argument
 */
int print_decimal(va_list args)
{
	int i = 0;
	int count = 0;
	long int number;
	int my_arr[10];
	char x[1];

	/*Fetch integer from variadic parameters*/
	number = va_arg(args, int);
	if (number < 0)
	{
		number = -((long int)(number));
		count = _putchar('-');
	}
	if (number > 0)
	{
		/*Break the numbers apart and assign them to array*/
		while (number != 0)
		{
			my_arr[i] = (number % 10);
			number /= 10;
			if (number == 0)
			{
				break;
			}
				i++;
		}
		/*Write the contents of the array to stdout*/
		for ((void)i; i >= 0; i--)
		{
			x[0] = ('0' + my_arr[i]); /*Convert int to char*/
			count += _putchar(x[0]);
		}

		return (count);
	}
	if (number == 0)
	{
		count = _putchar(number + '0');
	}
		return (count);
}

/**
 * print_integer - prints integer
 * @arg: list of arguments
 * Return: length of arguments
 */
int print_integer(va_list arg)
{
	int i = 0;
	int count = 0;
	long int number;
	int my_arr[10];
	char x[1];

	/*Fetch integer from variadic parameters*/
	number = va_arg(arg, int);
	if (number < 0)
	{
		number = -((long int)(number));
		count = _putchar('-');
	}
	if (number > 0)
	{
		/*Break the numbers apart and assign them to array*/
		while (number != 0)
		{
			my_arr[i] = (number % 10);
			number /= 10;
			if (number == 0)
			{
				break;
			}
				i++;
		}
		/*Write the contents of the array to stdout*/
		for ((void)i; i >= 0; i--)
		{
			x[0] = ('0' + my_arr[i]); /*Convert int to char*/
			count += _putchar(x[0]);
		}

		return (count);
	}
	if (number == 0)
	{
		count = _putchar(number + '0');
	}
	return (count);
}

