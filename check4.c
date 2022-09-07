#include "main.h"


/**
 *width - handles the field width for non-custom conversion specifiers
 *@numelse: number being printed
 *@len: used in counting the number of characters being printed
 *Return: nothing
 */

void width(int numelse, int *len)
{
int x, y = 100000;

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
