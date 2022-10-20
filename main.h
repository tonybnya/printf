#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct printer − structure for printing various types
 * @symbol: type to print
 * @func_t: function to print
 */

typedef struct printer
{
	const char symbol;
	int (*func_t)(va_list);
} printer_t;

int _write(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_str(va_list args);
int print_percent(__attribute__((unused))va_list args);
int print_decimal(va_list args);
int print_integer(va_list args);
int (*flags(const char s))(va_list);

#endif /* MAIN_H */
