#include "main.h"
#include "check.h"

/**
 *check2 - handles specifiers (u, o, x & X)
 *@str: list of variables to replace specifiers w\
ith
 *@format: the string being printed (containing s\
pecifiers)
 *@i: position of specifier indicator (%) in form\
at
 *@len: used in counting the number characters be\
ing printed
 *Return: nothing
 */

int check2(va_list str, const char *format, int *i, int *len)
{
if (format[(*i) + 1] == 'u')
*i = unsignint(str, i, len);

if (format[(*i) + 1] == 'o')
*i = octal(str, i, len);

if (format[(*i) + 1] == 'x' || format[(*i) + 1] == 'X')
*i = hexadec(str, format, i, len);

return (*i);
}
