#ifndef CHECK
#define CHECK

#include <limits.h>
#include "main.h"

/**
 *unsignint - handles unsigned int specifiers
 *@str: list of variables to replace specifiers with
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: i
 */

int unsignint(va_list str, const char *format, int *i, int *len)
{
__attribute__((unused)) unsigned long int x, x1, val;

if (format[(*i)] == '*')
{
val = va_arg(str, int);

if (val == '\0' && (format[(*i) - 1] == '.' || format[(*i) - 1] == '0'))
{
*i = (*i) + 1;

return (*i);
}
}

if (format[(*i)] == 'l')
x1 = va_arg(str, unsigned long int);
else
x = va_arg(str, unsigned int);

if (x == '\0' && (format[(*i)] == '.' || format[(*i)] == '0'))
{
*i = (*i) + 1;

return (*i);
}

if (format[(*i) - 1] == '.' || format[(*i) - 1] == '0')
{
if (format[(*i)] == '*')
{
if (val == '0' && x == 0)
*i = (*i) + 1;
prec(x, 'o', len, val);
}
else
prec(x, 'o',  len, atoi(&(format[*i])));
}

else if (format[(*i) - 1] == '-')
{
width(x, '-', len, atoi(&(format[*i]))), *i = (*i) + 1;
return (*i);
}

else if (format[(*i)] == '*')
width(x, 'o',  len, val);

else if (atoi(&(format[(*i)])) < 10 && format[(*i) - 1] == '1')
width(x, 'o',  len, atoi(&(format[*i])) + 10);


else if (atoi(&(format[(*i)])) < 10 && atoi(&(format[(*i)])) > 0)
width(x, 'o',  len, atoi(&(format[*i])));


if (format[(*i)] == 'l')
{
x = x1 / 10;
if (x != '\0')
print_number(x1 / 10, len);
print_number(x1 % 10, len);
}

else
print_number(x, len);

*i = (*i) + 1;

return (*i);
}


/**
 *octal - handles octal specifiers
 *@str: list of variables to replace specifiers with
 *@format: the string being printed (containing specifiers)
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: i
 */

int octal(__attribute__((unused)) va_list str, const char *format, int *i, int *len)
{
__attribute__((unused)) unsigned long int a, x, test;
__attribute__((unused)) int *bin = NULL, val;

if (format[(*i)] == '*')
{
val = va_arg(str, int);

if (val == '\0' && (format[(*i) - 1] == '.' || format[(*i) - 1] == '0'))
{
*i = (*i) + 1;

return (*i);
}

if (format[(*i)] == 'l')
test = va_arg(str, unsigned long int);
else
test = va_arg(str, long int);

if (format[(*i)] == '#' && test != 0)
_putchar('0'), *len = (*len) + 1;

if (test == 0)
{
if (format[(*i)] == '.' || format[(*i)] == '0')
{
*i = (*i) + 1;

return (*i);
}
if (format[(*i) - 1] == '.' || format[(*i) - 1] == '0')
{
if (format[(*i)] == '*')
{
if (val == '0')
*i = (*i) + 1;
prec(test, 'n', len, val);
}
else if (format[(*i)] == '0')
*i = (*i) + 1;
else
prec(test, 'n', len, atoi(&(format[*i])));
}
else if (format[(*i) - 1] == '-')
width(test, '-', len, atoi(&(format[*i])));
else if (format[(*i)] == '.')
*i = (*i) + 1;
else if (format[(*i) - 1] != '-')
print_number(0, len);
}

else
{
for (x = test, a = 1; x > 0; x = (x / 8), a++)
{
bin = realloc(bin, (sizeof(int) * (a + 1)));
bin[a] = x % 8;
}

if (format[(*i) - 1] == '.' || format[(*i) - 1] == '0')
{
if (format[(*i)] == '*')
prec(a, 'x', len, val);
else
prec(a, 'x', len, atoi(&(format[*i])));
}
else if (format[(*i)] == '*')
width(a, 'x', len, val);
else if (atoi(&(format[(*i)])) < 10 && format[(*i) - 1] == '1')
width(a, 'x', len, atoi(&(format[*i])) + 10);
else if ((atoi(&(format[(*i)])) < 10 && atoi(&(format[(*i)])) > 0)  && format[(*i) - 1] != '-')
width(a, 'x', len, atoi(&(format[*i])));

for (x = a - 1; x >= 1; x--)
{
print_number(bin[x], len);
}
if (format[(*i) - 1] == '-')
width(a, 'x', len, atoi(&(format[*i])));
}
*i = (*i) + 1;
return (*i);
}


/**
 *hexadec - handles hexadecimal specifiers
 *@str: list of variables to replace specifiers with
 *@format: the string being printed (containing specifiers)
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: i
 */

int hexadec(va_list str, const char *format, int *i, int *len)
{
unsigned long int a, x, test;
__attribute__((unused)) char low[] = "0123456789abcdef";
__attribute__((unused)) char upp[] = "0123456789ABCDEF";
__attribute__((unused)) int *bin = NULL, b, val;

if (format[(*i)] == '*')
{
val = va_arg(str, int);

if (val == '\0' && (format[(*i) - 1] == '.' || format[(*i) - 1] == '0'))
{
*i = (*i) + 1;

return (*i);
}

if (format[(*i)] == 'l')
test = va_arg(str, unsigned long int);
else
test = va_arg(str, unsigned int);

if (format[(*i)] == '#' && test != 0)
_putchar('0'), _putchar(format[(*i) + 1]), *len = (*len) + 2;

if (test == 0)
{
if (format[(*i)] == '.' || format[(*i)] == '0')
{
*i = (*i) + 1;

return (*i);
}
if (format[(*i) - 1] == '.' || format[(*i) - 1] == '0')
{
if (format[(*i)] == '*')
{
if (val == '0')
*i = (*i) + 1;
prec(test, 'n', len, val);
}
else if (format[(*i)] == '0')
*i = (*i) + 1;
else
prec(test, 'n', len, atoi(&(format[*i])));
}
else if (format[(*i) - 1] == '-')
width(test, '-', len, atoi(&(format[*i])));
else if (format[(*i)] == '.')
*i = (*i) + 1;
else if (format[(*i)] == '*')
width(test, 'n', len, val);
else if (atoi(&(format[(*i)])) < 10 && format[(*i) - 1] == '1')
width(test, 'n', len, atoi(&(format[*i])) + 10);
else if ((atoi(&(format[(*i)])) < 10 && atoi(&(format[(*i)])) > 0))
width(test, 'n', len, atoi(&(format[*i])));
if (format[(*i) - 1] != '-')
print_number(0, len);
}

else
{
for (x = test, a = 1; x > 0; x = (x / 16), a++)
{
bin = realloc(bin, (sizeof(int) * (a + 1)));
bin[a] = x % 16;
}

if (format[(*i) - 1] == '.' || format[(*i) - 1] == '0')
{
if (format[(*i)] == '*')
prec(a, 'x', len, val);
else
prec(a, 'x', len, atoi(&(format[*i])));
}
else if (format[(*i)] == '*')
width(a, 'x', len, val);
else if (atoi(&(format[(*i)])) < 10 && format[(*i) - 1] == '1')
width(a, 'x', len, atoi(&(format[*i])) + 10);
else if ((atoi(&(format[(*i)])) < 10 && atoi(&(format[(*i)])) > 0) && format[(*i) - 1] != '-')
width(a, 'x', len, atoi(&(format[*i])));

for (x = a - 1; x >= 1; x--)
{
if (format[(*i) + 1] == 'x')
{
for (b = 0; low[b] != '\0'; b++)
{
if (bin[x] == b)
{
_putchar(low[b]);
*len = (*len) + 1; } } }
else if (format[(*i) + 1] == 'X')
{
for (b = 0; upp[b] != '\0'; b++)
{
if (bin[x] == b)
{
_putchar(upp[b]);
*len = (*len) + 1; } } } }
if (format[(*i) - 1] == '-')
width(a, 'x', len, atoi(&(format[*i])));
}
*i = (*i) + 1;
return (*i);
}
#endif
