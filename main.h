#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void width(int numelse, int *len);
int check4(va_list str, const char *format, int *i, int *len);
int check3(va_list str, const char *format, int *i, int *len);
int check2(va_list str, const char *format, int *i, int *len);
int check(va_list str, const char *format, int *i, int *len);
int checker(va_list str, const char *format, int *i, int *len);
int binary(va_list str, int *i, int *len);
int numbers(va_list str, const char *format, int *i, int *len);
int word(va_list str, const char *format, int *i, int *len);
void null(__attribute__((unused)) int *len);
void nil(__attribute__((unused)) int *len);
int _printf(char *format, ...);
int _putchar(char c);
void print5(unsigned long int n, int *len);
void print_contd(unsigned long int n, int *len);
void print_number(long int n, int *len);

#endif
