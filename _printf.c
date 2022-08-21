#include "main.h"

/**
 *_printf- produces output accorting to a format
 *@format: character string
 *Return: the number of characters printed
 *excluding the null byte used to end output to strings
 */

int _printf(const char *format, ...)
{
__attribute__((unused)) int i, x;
__attribute__((unused)) char *words;
va_list str;

va_start (str, format);

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's'))
{
if (format[i + 1] == 'c')
_putchar(va_arg(str, int));

else if (format[i + 1] == 's')
{
words = va_arg(str, char *);
 for (x = 0; words[x] != '\0'; x++)
{
_putchar(words[x]);
}
}

i++;
}
else
{
_putchar(format[i]);
}
}
return (i);
}
