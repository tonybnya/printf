#include "main.h"

/**
 * _printf − our version of printf() function in C.
 * @format: string representing the format of arguments
 * @...: variadic arguments
 *
 * Return: void
 */
int _printf(const char *format, ...)
{
	va_list args;
	int result;
	
	va_start(args, format);
	
	result = print(format, args);
	
	va_end(args);
	
	return (result);
}
