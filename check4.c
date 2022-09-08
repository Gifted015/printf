#include "main.h"


/**
 *prec - handles the precision for non-custom conversion specifiers
 *@numelse: number being printed
 *@spec: conversion specifiers indicator
 *@len: used in counting the number of characters being printed
 *Return: i
 */

void prec(int numelse, char spec, int *len)
{
int x, y = 100000;
if (spec == 'x')
{
for (x = 0; x <= 6 - numelse; x++)
{
_putchar('0');
*len = (*len) + 1;
}
}

else if (spec == 's')
{
for (x = 1; x <= 6 - numelse; x++)
{
_putchar('0');
*len = (*len) + 1;
}
}

else if (spec == 'c')
{
for (x = 1; x < 6; x++)
{
_putchar('0');
*len = (*len) + 1;
}
}

else
{
if (numelse == 0)
{
for (x = 1; x < 6; x++)
{
_putchar('0');
*len = (*len) + 1;
}
}

if (numelse < 0)
{
y = 10000;
}

if (numelse != 0 && numelse < 1000000)
{
for (x = numelse; x / y == 0; y = y/10)
{
_putchar('0'), *len = (*len) + 1;
}
}
}
}


/**
 *width - handles the field width for non-custom conversion specifiers
 *@numelse: number being printed
 *@spec: conversion specifiers indicator
 *@len: used in counting the number of characters being printed
 *Return: i
 */

void width(int numelse, char spec, int *len)
{
int x, y = 100000;
if (spec == 'x')
{
for (x = 0; x <= 6 - numelse; x++)
{
_putchar(' ');
*len = (*len) + 1;
}
}

else if (spec == 's')
{
for (x = 1; x <= 6 - numelse; x++)
{
_putchar(' ');
*len = (*len) + 1;
}
}

else if (spec == 'c')
{
for (x = 1; x < 6; x++)
{
_putchar(' ');
*len = (*len) + 1;
}
}

else
{
if (numelse == 0)
{
for (x = 1; x < 6; x++)
{
_putchar(' ');
*len = (*len) + 1;
}
}

if (numelse < 0)
{
y = 10000;
}

if (numelse != 0 && numelse < 1000000)
{
for (x = numelse; x / y == 0; y = y/10)
{
_putchar(' '), *len = (*len) + 1;
}
}
}
}


/**
 *check5 - handles non-custom specifiers ('.')
 *@str: list of variables to replace specifiers with
 *@format: the string being printed (containing specifiers)
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: i
 */

int check5(va_list str, const char *format, int *i, int *len)
{
if (format[(*i) + 1] == '.')
{
*i = (*i) + 2;
if (format[(*i) + 1] == '\0')
*len = -1;
*i = check(str, format, i, len);
}
return (*i);
}

/**
 *check4 - handles non-custom specifiers ('+', ' ' & '#')
 *@str: list of variables to replace specifiers with
 *@format: the string being printed (containing specifiers)
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: nothing
 */

int check4(va_list str, const char *format, int *i, int *len)
{
if (format[(*i) + 1] == '+')
{
*i = numbers(str, format, i, len);
}

else if (format[(*i) + 1] == '*')
{
*i = (*i) + 1;
va_arg(str, int);
if (format[(*i) + 1] == '\0')
*len = -1;
*i = check(str, format, i, len);
}

else if (format[(*i) + 1] == ' ' || format[(*i) + 1] == '6')
{
*i = (*i) + 1;
if (format[(*i) + 1] == '\0')
*len = -1;
*i = check(str, format, i, len);
}

else if (format[(*i) + 1] == '#')
{
*i = (*i) + 1;
*i = check(str, format, i, len);
}

else if (format[(*i) + 1] == 'l')
{
*i = (*i) + 1;
*i = check(str, format, i, len);
}

else if (format[(*i) + 1] == 'h')
{
*i = (*i) + 1;
*i = check(str, format, i, len);
}

return (*i);
}
