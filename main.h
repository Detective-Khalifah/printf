#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#define INT_MAX 2147483647

int _putchar(int c);
int icharacter(int ch);
void istring(char *str);
int idigit(long n, int base);

int process_pointer(va_list args);
int process_string_escape(va_list args);
int process_unknown(char specifier);
int process_hex(va_list args);
int process_octal(va_list args);
int process_binary(va_list args);
int process_unsigned_int(va_list args);
int process_int(va_list args);
int process_string(va_list args);
int process_char(va_list args);

int process_specifier(va_list args, char specifier);

int check_specifier(va_list args, char specifier);

int print_format(const char *format, va_list args);
int _printf(const char *format, ...);


#endif /* MAIN_H */

