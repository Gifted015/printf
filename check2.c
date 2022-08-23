#include "main.h"

/**
 *unsignint - handles unsigned int specifiers
 *@str: list of variables to replace specifiers with
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: nothing
 */

int unsignint(va_list str, int *i, int *len)
{
__attribute__((unused)) unsigned int x;

x = va_arg(str, unsigned int);
print_number(x, len);
*i = (*i) + 1;

return (*i);
}


/**
 *check2 - handles specifiers (u, o, x & X)
 *@str: list of variables to replace specifiers with
 *@format: the string being printed (containing specifiers)
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: nothing
 */

int check2(va_list str, const char *format, int *i, int *len)
{
if (format[(*i) + 1] == 'u')
*i = unsignint(str, i, len);

return (*i);
}
