#include "main.h"

void inscribe(const char *format, ...)
{
	va_list arg_p;

	va_start(arg_p, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			check_specifier(arg_p, *(++format));
			break;
		}
		else
		{
			icharacter(*format);
		}

		format++;
	}

	va_end(arg_p);
}
