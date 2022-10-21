#include "main.h"

/**
 * flags − function to find a function pointer
 * associated with specifier
 *
 * @a: specifier to find the correct function
 *
 * Return: function pointer
 */
int (*flags(const char ch))(va_list)
{
	unsigned int idx = 0;

	printer_t ops[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		{'d', print_decimal},
		{'i', print_integer},
		{'\0', NULL}
	};

	for (; ops[idx].symbol; idx++)
	{
		if (ch == ops[idx].symbol)
			return (ops[idx].func_t);
	}

	return (NULL);
}
