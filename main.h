#ifndef MAIN_H
#define MAIN_H

#define BUFSIZE 1024

#include <ctype.h>
#include <limits.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct printer - structure for printing various types
 * @symbol: type to print
 * @func_t: function to print
 */
typedef struct printer
{
	const char symbol;
	int (*func_t)(va_list);
} printer_t;

int print(const char *format, va_list args);
int _write(char c);
int print_char(va_list arg_list);
int print_string(va_list arg_list);
int print_percent(__attribute__((unused))va_list arguments);
int (*flags(const char c))(va_list);

#endif /* MAIN_H */
