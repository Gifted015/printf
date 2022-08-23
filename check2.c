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
 *octal - handles octal specifiers
 *@str: list of variables to replace specifiers with
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: nothing
 */

int octal(__attribute__((unused)) va_list str, int *i, int *len)
{
unsigned int a, x, test,  *bin;
test = va_arg(str, int);

if (test == 0)
{
print_number(0, len);
}

else
{
for (x = test, a = 1; x > 0; x = (x / 8), a++)
{
bin = realloc(bin, (sizeof(int) * (a + 1)));
bin[a] = x % 8;
}

for (x = a - 1; x >= 1; x--)
{
print_number(bin[x], len);
}
free(bin);
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
 *Return: nothing
 */

int hexadec(va_list str, const char *format, int *i, int *len)
{
if (format[(*i) + 1] == 'x')
{
va_arg(str, int);
*i = (*i) + 1;
*len = (*len) + 1;
}


else if (format[(*i) + 1] == 'X')
{
*i = (*i) + 1;
*len = (*len) + 1;
}


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

if (format[(*i) + 1] == 'o')
*i = octal(str, i, len);

/*
*if (format[(*i) + 1] == 'x' || format[(*i) + 1] == 'X')
*i = hexadec(str, format, i, len);
*/
return (*i);
}
