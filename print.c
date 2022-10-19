#include "main.h"

/**
 * print - prints formatted arguments
 * @format: string representing the format of arguments
 * @args: variadic arguments
 *
 * mode:
 * 0 - simple printing
 * 1 - escape printing
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
				_putchar(*format);
		}
		else if (mode == 1)
		{
			switch (*format)
			{
				case 'c':
				{
					char ch = va_arg(args, int);

					result = _putchar(ch);
					break;
				}

				case 's':
				{
					const char *str = va_arg(args, const char *);

					while (*str)
					{
						result = _putchar(*str++);
					}
					break;
				}

				case '%':
				{
					result += _putchar('%');
				}
			}
		}

		format++;
	}

	return (result);
}
