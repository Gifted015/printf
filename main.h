#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdarg.h>

int check(va_list str, const char *format, __attribute__((unused)) int *i, __attribute__((unused)) int *len);
void null(__attribute__((unused)) int *len);
int _printf(const char *format, ...);
int _putchar(char c);
void print_number(int n);

#endif
