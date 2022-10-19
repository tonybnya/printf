#include "main.h"

/**
 * unsigned_num2str - transform an unsigned number to string
 * @num: the given positive number
 * @base: base for the conversion of the integer
 * @buffer: buffer to holds temp data
 *
 * Return: void
 */
void unsigned_num2str(uint64_t num, int base, char *buffer)
{
	char num_buf[65];
	int curr, digit, i, j;

	if (num == 0)
	{
		*buffer++ = '0';
		*buffer = 0;
		return;
	}

	for (i = 0; i < 65; i++)
		num_buf[i] = 0;

	curr = 0;
	while (num)
	{
		digit = num % base;
		if (digit >= 10)
			num_buf[curr++] = 'a' + (digit - 10);
		else
			num_buf[curr++] = '0' + digit;

		num /= base;
	}

	for (j = curr - 1; j != 0; j--)
		*buffer++ = num_buf[j];

	*buffer++ = num_buf[0];
	*buffer = 0;
}

/**
 * num2str - transform any number (positive or negative) to string
 * @num: the given number
 * @base: base for the conversion of the integer
 * @buffer: buffer to holds temp data
 *
 * Return: void
 */
void num2str(int64_t num, int base, char *buffer)
{
	if (num < 0)
	{
		*buffer++ = '-';
		num = -num;
	}

	unsigned_num2str(num, base, buffer);
}

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

				case 'f':
				{
					break;
				}

				case 'o':
				{
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
