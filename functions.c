#include "main.h"

/**
 * print_char - prints a character
 * @args: variadic arguments
 *
 * Return: num of the characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (_write(c));
}

/**
 * print_str -prints string of characters
 * @args: variadic arguments
 *
 * Return: num of parameters printed
 */
int print_str(va_list args)
{
	int i, count = 0;
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
		count += _write(str[i]);

	return (count);
}

/**
 * print_percent - prints the character %
 * @args: unused
 *
 * Return: Always 1
 */
int print_percent(__attribute__((unused))va_list args)
{
	char c = '%';

	_write(c);

	return (1);
}

/**
 * print_decimal - prints a decimal
 * @args: decimal to print
 *
 * Return: number of characters and digits printed
 */
int print_decimal(va_list args)
{
	int x[10];
	int f, d, t, y, i;

	t = va_arg(args, int);
	i = 0;
	d = 1000000000;
	x[0] = t / d;

	for (f = 1; f < 10; f++)
	{
		d /= 10;
		x[f] = (t / d) % 10;
	}

	if (t < 0)
	{
		_write('-');
		i++;

		for (f = 0; f < 10; f++)
			x[f] *=	-1;
	}

	for (f = 0, y = 0; f < 10; f++)
	{
		y += x[f];

		if (y != 0 || f == 9)
		{
			_write('0' + x[f]);
			i++;
		}
	}

	return (i);
}

/**
 * print_integer - prints an integer
 * @args: integer to print
 *
 * Return: number of characters and digits printed
 */
int print_integer(va_list args)
{
	int x[10];
	int f, d, t, y, i;

	t = va_arg(args, int);
	i = 0;
	d = 1000000000;
	x[0] = t / d;

	for (f = 1; f < 10; f++)
	{
		d /= 10;
		x[f] = (t / d) % 10;
	}

	if (t < 0)
	{
		_write('-');
		i++;

		for (f = 0; f < 10; f++)
			x[f] *= -1;
	}

	for (f = 0, y = 0; f < 10; f++)
	{
		y += x[f];

		if (y != 0 || f == 9)
		{
			_write('0' + x[f]);
			i++;
		}
	}

	return (i);
}
