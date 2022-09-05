#ifndef CHECK
#define CHECK

#include <limits.h>
#include "main.h"

/**
 *unsignint - handles unsigned int specifiers
 *@str: list of variables to replace specifiers with
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: nothing
 */

int unsignint(va_list str, const char *format, int *i, int *len)
{
__attribute__((unused)) unsigned long int x;
__attribute__((unused)) unsigned long int x1;
if (format[(*i)] == 'l')
x1 = va_arg(str, unsigned long int);
else
x = va_arg(str, unsigned int);

if (format[(*i)] == 'l')
{
x = x1 / 10;
if (x != '\0')
print_number(x1 / 10, len);
print_number(x1 % 10, len);
}
else
print_number(x, len);
*i = (*i) + 1;
return (*i);
}


/**
 *octal - handles octal specifiers
 *@str: list of variables to replace specifiers with
 *@format: the string being printed (containing specifiers)
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: nothing
 */

int octal(__attribute__((unused)) va_list str, const char *format, int *i, int *len)
{
unsigned long int a, x, *bin = NULL, test;

test = va_arg(str, int);

if (format[(*i)] == '#' && test != 0)
_putchar('0'), *len = (*len) + 1;

if (test == 0)
{
print_number(0, len);
}

else
{
for (x = test, a = 1; x > 0; x = (x / 8), a++)
{
bin = realloc(bin, (sizeof(int) * (a + 1)));
bin[a] = x % 8;
}

for (x = a - 1; x >= 1; x--)
{
print_number(bin[x], len);
}
}
*i = (*i) + 1;
return (*i);
}


/**
 *hexadec - handles hexadecimal specifiers
 *@str: list of variables to replace specifiers with
 *@format: the string being printed (containing specifiers)
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: nothing
 */

int hexadec(va_list str, const char *format, int *i, int *len)
{
unsigned long int a, b, x, *bin = NULL;
__attribute__((unused)) char low[] = "0123456789abcdef";
__attribute__((unused)) char upp[] = "0123456789ABCDEF";
__attribute__((unused)) unsigned long int test;

test = va_arg(str, unsigned int);

if (format[(*i)] == '#' && test != 0)
_putchar('0'), _putchar(format[(*i) + 1]), *len = (*len) + 2;

if (test == 0)
{
print_number(0, len);
}

else
{
for (x = test, a = 1; x > 0; x = (x / 16), a++)
{
bin = realloc(bin, (sizeof(int) * (a + 1)));
bin[a] = x % 16;
}
for (x = a - 1; x >= 1; x--)
{
if (format[(*i) + 1] == 'x')
{
for (b = 0; low[b] != '\0'; b++)
{
if (bin[x] == b)
{
_putchar(low[b]);
*len = (*len) + 1; } } }
else if (format[(*i) + 1] == 'X')
{
for (b = 0; upp[b] != '\0'; b++)
{
if (bin[x] == b)
{
_putchar(upp[b]);
*len = (*len) + 1; } } } } }
*i = (*i) + 1;
return (*i);
}
#endif
