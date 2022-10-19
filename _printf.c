#include "main.h"

/**
 * _printf − our version of printf() function in C.
 * @format: string representing the format of arguments
 * @...: variadic arguments
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int result = 0, i;
	int (*func)(va_list);
	
	va_start(args, format);

	if (format == NULL)
		return (-1);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);

			func = flags(format[i]);

			if (func == NULL)
			{
				_write('%');
				_write(format[i]);
				result += 2;
			}
			else
			{
				result += func(args);
			}
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
