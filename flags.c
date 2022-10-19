#include "main.h"

/**
 * flags - finds function pointer with specifier
 * @a: specifier
 *
 * Return: function pointer
 */
int (*flags(const char c))(va_list)
{
	unsigned int m = 0;

	printer_t ops[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'i', print_integer},
		{'d', print_decimal},
		{'b', print_binary},
		{'u', print_unint},
		{'o', print_octal},
		{'R', rot13},
		{'r', print_reversed},
		{'\0', NULL}
	};

	for (; ops[m].symbol; m++)
	{
		if (c = ops[m].symbol)
			return (ops[m].func_t);
	}

	return (NULL);
}
