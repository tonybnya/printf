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
	void *ptr_num;
	int result;
	int i;
	int is_long = 0;
	int mode = 0;
	int reset = 1;
	char num_buf[65];

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

				case 'd':
				case 'i':
				{
					int64_t num;

					if (is_long == 1)
					{
						num = va_arg(args, long);
					}
					else
					{
						num = va_arg(args, int);
					}

					num2str(num, 10, num_buf);

					for (i = 0; num_buf[i]; i++)
					{
						result += _putchar(num_buf[i]);
					}
					break;
				}

				case 'u':
				{
					unsigned int num;

					if (is_long == 1)
					{
						num = va_arg(args, long);
					}
					else
					{
						num = va_arg(args, int);
					}

					unsigned_num2str(num, 10, num_buf);

					for (i = 0; num_buf[i]; i++)
					{
						result += _putchar(num_buf[i]);
					}
					break;
				}

				case 'l':
				{
					is_long = 1;
					reset = 0;
					break;
				}

				case 'x':
				{
					uint64_t num;

					if (is_long == 1)
					{
						num = va_arg(args, unsigned long);
					}
					else
					{
						num = va_arg(args, unsigned int);
					}

					unsigned_num2str(num, 16, num_buf);

					for (i = 0; num_buf[i]; i++)
						result += _putchar(num_buf[i]);
					break;
				}

				case 'X':
				{
					uint64_t num;

					if (is_long == 1)
					{
						num = va_arg(args, unsigned long);
					}
					else
					{
						num = va_arg(args, unsigned int);
					}

					unsigned_num2str(num, 16, num_buf);

					for (i = 0; num_buf[i]; i++)
					{
						if (isalpha(num_buf[i]))
						{
							char c = toupper(num_buf[i]);
							result += _putchar(c);
						}
						else
						{
							result += _putchar(num_buf[i]);
						}
					}
					break;
				}

				case 'p':
				{
					result += _putchar('0');
					result += _putchar('x');

					ptr_num = va_arg(args, void *);
					unsigned_num2str((uint64_t) ptr_num, 16, num_buf);

					for (i = 0; num_buf[i]; i++)
						result += _putchar(num_buf[i]);
					break;
				}

				case '%':
				{
					result += _putchar('%');
				}
			}

			if (reset == 1)
			{
				mode = 0;
				is_long = 0;
			}
			else
			{
				reset = 1;
			}
		}

		format++;
	}

	return (result);
}
