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
