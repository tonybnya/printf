#ifndef MAIN_H
#define MAIN_H

#include <ctype.h>
#include <limits.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int _write(char c);
int print(const char *format, va_list args);
int _putchar(char c);
void unsigned_num2str(uint64_t num, int base, char *buffer);
void num2str(int64_t num, int base, char *buffer);

#endif /* MAIN_H */
