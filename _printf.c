#include "main.h"
#include <string.h>

/**
 *_printf - produces output accorting to a format
 *@format: character string
 *Return: the number of characters printed
 *excluding the null byte used to end output to strings
 */

int _printf(const char *format, ...)
{
__attribute__((unused)) int k = 0, j = 0, *i, *len, a, b = 0;
__attribute__((unused)) char *buf;
len = &k;
i = &j;
if (format != NULL)
{
va_list str;
va_start(str, format);
buf = format;
while (buf)
{
for (*i = 0; buf[(*i)] != '\0'; *i = (*i) +1)
{
if (buf[(*i)] == '%')
break;
}
if (buf[(*i)] == '%')
break;
*len = write(1, buf, 1024) + (*len);
b = 1;
buf = va_arg(str, char *); }
va_end(str);
va_start(str, format);
if (b != 1)
{
for (*i = 0; format[(*i)] != '\0'; *i = (*i) +1)
{
if (format[(*i)] == '%')
{
*i = check(str, format, i, len); }
else
{
_putchar(format[(*i)]);
*len = (*len) +1; } } }
va_end(str); }
else
return (-1);

return (*len);
}
