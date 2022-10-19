#include "main.h"

/**
 * print_char - Print characters (%c)
 * @arg_list: Stores a list of characters
 *
 * Return: num of characters printed
 */
int print_char(va_list arg_list)
{
	char c = va_arg(arg_list, int);

	return (_write(c));
}

/**
 * print_string - print string (%s)
 * @arg_list: Stores a list of characters
 * Return: num of parameters printed
 */
int print_string(va_list arg_list)
{
	int i, count = 0;
	char *str;

	str = va_arg(arg_list, char *);
	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
		count += _write(str[i]);

	return (count);

}

/**
 * print_percent - function to print %
 * @arguments: unused
 *
 * Return: always 1
 */
int print_percent(__attribute__((unused))va_list arguments)
{
	char c = '%';

	_write(c);
	return (1);
}
