#include "main.h"

/**
 * _write - writes a character c stdout
 * @c: A character
 *
 * Return: 1 on success, -1 on error
 */
int _write(char c)
{
	return (write(1, &c, 1));
}
