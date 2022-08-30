#include "main.h"

/**
 *checker - handles specifiers (S)
 *@str: list of variables to replace specifiers with
 *@format: the string being printed (containing specifiers)
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: nothing
 */

int checker(va_list str, const char *format, int *i, int *len)
{
check4(str, format, i, len);

if (format[(*i) + 1] == 'c' || format[(*i) + 1] == 's')
*i = word(str, format, i, len);

else if (format[(*i) + 1] == 'd' || format[(*i) + 1] == 'i')
*i = numbers(str, format, i, len);

else if (format[(*i) + 1] == 'b')
*i = binary(str, i, len);

else if (format[(*i) + 1] == '%')
{
_putchar(format[(*i)]);
*i = (*i) + 1;
*len = (*len) + 1;
}
return (*i);
}
