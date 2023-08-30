#include "main.h"

/**
 * istring - writes a character array (string) to stdout
 * @str: pointer to character array to print
 */
void istring(char *str)
{
	while (*str != '\0')
	{
		icaracter((int)(*str));
		str++;
	}
}
