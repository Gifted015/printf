#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int check2(va_list str, const char *format, __attribute__((unused)) int *i, __attribute__((unused)) int *len);
int check(va_list str, const char *format, __attribute__((unused)) int *i, __attribute__((unused)) int *len);
void null(__attribute__((unused)) int *len);
int _printf(char *format, ...);
int _putchar(char c);
void print_contd(long int n, int *len);
void print_number(long int n, int *len);

#endif
