#include "main.h"


/**
 *prec - handles the precision for non-custom conversion specifiers
 *@numelse: number being printed
 *@spec: conversion specifiers indicator
 *@len: used in counting the number of characters being printed
 *@count: number of zeros to be added
 *Return: i
 */

int prec(int numelse, char spec, int *len, int count)
{
int x, y = _pow(10, (count - 1));
if (spec == 'x')
{
for (x = 0; x <= count - numelse; x++)
{
_putchar('0');
*len = (*len) + 1;
}
}

else if (spec == 's')
{
if (numelse > count)
numelse = count;
}

else if (spec == 'c')
{
for (x = 1; x < count; x++)
{
_putchar('0');
*len = (*len) + 1;
}
}

else
{
if (numelse == 0)
{
for (x = 1; x < count; x++)
{
_putchar('0');
*len = (*len) + 1;
}
}

if (numelse < 0)
{
_putchar('-'), *len = (*len) + 1;
if (spec == '0')
y = _pow(10, (count - 2));
}


if (numelse != 0 && numelse < 1000000)
{
for (x = numelse; x / y == 0; y = y/10)
{
_putchar('0'), *len = (*len) + 1;
}
}
}
if (numelse < 0)
return (-numelse);
else
return (numelse);
}


/**
 *width - handles the field width for non-custom conversion specifiers
 *@numelse: number being printed
 *@spec: conversion specifiers indicator
 *@len: used in counting the number of characters being printed
 *@count: number of spaces to be added
 *Return: i
 */

void width(int numelse, char spec, int *len, int count)
{
int x, y = _pow(10, (count - 1));
if (spec == 'x')
{
for (x = 0; x <= count - numelse; x++)
{
_putchar(' ');
*len = (*len) + 1;
}
}

else if (spec == 's')
{
for (x = 1; x <= count - numelse; x++)
{
_putchar(' ');
*len = (*len) + 1;
}
}

else if (spec == 'c')
{
for (x = 1; x < count; x++)
{
_putchar(' ');
*len = (*len) + 1;
}
}

else
{
if (spec == '-')
print_number(numelse, len);

if (numelse == 0)
{
for (x = 1; x < count; x++)
{
_putchar(' ');
*len = (*len) + 1;
}
}

if (numelse < 0)
{
y = _pow(10, (count - 2));
}

if (numelse != 0 && numelse < _pow(10, count))
{
for (x = numelse; x / y == 0; y = y/10)
{
_putchar(' '), *len = (*len) + 1;
}
}
}
}


/**
 *check5 - handles non-custom specifiers '.', '0' and '-'
 *@str: list of variables to replace specifiers with
 *@format: the string being printed (containing specifiers)
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: i
 */

int check5(va_list str, const char *format, int *i, int *len)
{
__attribute__((unused)) char norm[] = "diuoxX";
__attribute__((unused)) int x;

for (x = 0; x < 6; x++)
{
if (format[(*i) + 2] == norm[x])
break;
}
 
if (format[(*i) + 2] == '*' || (format[(*i) + 2] > 47 && format[(*i) + 2] < 55))
{
if (format[(*i) + 3] > 48 && format[(*i) + 3] < 58)
*i = (*i) + 3;
else
*i = (*i) + 2;
if (format[(*i) + 1] == '\0')
*len = -1;
*i = check(str, format, i, len);
}

else if (format[(*i) + 2] == norm[x])
{
*i = (*i) + 1;
*i = check(str, format, i, len);
}

else
*i = (*i) + 2;

return (*i);
}

/**
 *check4 - handles non-custom specifiers ('+', ' ', 'l', 'h', '*', '#' && numbers)
 *@str: list of variables to replace specifiers with
 *@format: the string being printed (containing specifiers)
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: nothing
 */

int check4(va_list str, const char *format, int *i, int *len)
{
if (format[(*i) + 1] == '+' || format[(*i) + 1] == ' ')
{
*i = numbers(str, format, i, len);
}

else if (format[(*i) + 1] == '*')
{
*i = (*i) + 1;
if (format[(*i) + 1] == '\0')
*len = -1;
*i = check(str, format, i, len);
}

else if (format[(*i) + 1] > 48 && format[(*i) + 1] < 58)
{
if (format[(*i + 2)] > 48 && format[(*i) + 2] < 58)
*i = (*i) + 2;
else
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
