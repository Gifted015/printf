#include "main.h"

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
numbers(str, format, i, len);
}

else if (format[(*i) + 1] == ' ')
{
*i = (*i) + 1;
}

else if (format[(*i) + 1] == '#')
{
*i = (*i) + 1;
}

return (*i);
}