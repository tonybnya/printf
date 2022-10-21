#include "main.h"

/**
 * _printf - printf anything
 * @format: type of the argument
 * @...: variadic list of arguments
 *
 * Return: number if characters printed
 */
int _printf(const char *format, ...)
{
	int i, result = 0;
	va_list args;
	int (*func)(va_list);

	va_start(args, format);

	if (format == NULL)
		return (-1);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (!(format[i]))
				return (-1);

			func = flags(format[i]);

			if (func == NULL)
			{
				_write('%');
				_write(format[i]);
				result += 2;
			}
			else
				result += func(args);
		}
		else
		{
			_write(format[i]);
			result++;
		}
	}
	va_end(args);
	return (result);
}
