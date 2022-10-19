#include "main.h"

/**
 * print - prints formatted arguments
 * @format: string representing the format of arguments
 * @args: variadic arguments
 *
 * Return: void
 */
int print(const char *format, va_list args)
{
	int result;
	int mode = 0;

	while (*format)
	{
		if (mode == 0)
		{
			if (*format == '%')
				mode = 1;
			else
				write(*format);
		}
		else if (mode == 1)
		{
			switch (*format)
			{
				case 'c':
				{
					char ch = va_arg(args, int);

					result = write(ch);
					break;
				}

				case 's':
				{
					const char *str = va_arg(args, const char *);

					while (*str)
					{
						result = write(*str++);
					}
					break;
				}

				case '%':
				{
					result += write('%');
				}
			}
		}

		format++;
	}

	return (result);
}
