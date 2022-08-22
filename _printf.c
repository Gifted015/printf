#include "main.h"

/**
 *null - prints the string "(null)"
 *@len: used to add the lenght of "null" to
 *the lenght of string originally printed
 *Return: nothing
 */

void null(__attribute__((unused)) int *len)
{
int x;
char empty[] = "(null)";

for (x = 0; empty[x] != '\0'; x++)
{
_putchar(empty[x]);
*len = (*len) + 1;
}
}


/**
 *check - handles specifiers
 *@len: used to add the lenght of "null" to
 *the lenght of string originally printed
 *Return: nothing
 */

void check(va_list str, const char *format, __attribute__((unused)) int *i, __attribute__((unused)) int *len)
{
__attribute__((unused)) int x, in, dec;
__attribute__((unused)) char *words, chr;

if (format[(*i) + 1] == 'c')
{
chr = va_arg(str, int), _putchar(chr); *len = (*len) + 1, *i = (*i) + 1; }

else if (format[(*i) + 1] == 'd')
{
dec = va_arg(str, int), print_number(dec); *len = (*len) + 1, *i = (*i) + 1; }

else if (format[(*i) + 1] == 'i')
{
in = va_arg(str, int), print_number(in); *len = (*len) + 1, *i = (*i) + 1; }

else if (format[(*i) + 1] == 's')
{
words = va_arg(str, char *);
if (words == NULL)
{
null(len); }
else
{
for (x = 0; words[x] != '\0'; x++)
{
_putchar(words[x]), *len = (*len) + 1; } }
*i = (*i) + 1; }

else if (format[(*i) + 1] == '%')
{
_putchar(format[(*i)]), *i = (*i) + 1, *len = (*len) + 1; }

else
{
if (format[(*i) + 1] == '\0')
*len = -1;
else
_putchar(format[(*i)]), *len = (*len) + 1; } }


/**
 *_printf - produces output accorting to a format
 *@format: character string
 *Return: the number of characters printed
 *excluding the null byte used to end output to strings
 */

int _printf(const char *format, ...)
{
__attribute__((unused)) int k = 0, j = 0,  *i, *len;

len = &k;
i = &j;

if (format != NULL)
{
va_list str;
va_start(str, format);
for (*i = 0; format[(*i)] != '\0'; *i = (*i) + 1)
{
if (format[(*i)] == '%')
{
check(str, format, i, len);
}
else
{
_putchar(format[(*i)]), *len = (*len) + 1; } }
va_end(str);
}
else
return (-1);
return (*len); }
