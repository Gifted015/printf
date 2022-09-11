#include "main.h"


/**
 *check6 - handles non-custom specifiers ('.')
 *@str: list of variables to replace specifiers with
 *@format: the string being printed (containing specifiers)
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: i
 */

int check6(va_list str, const char *format, int *i, int *len)
{
__attribute__((unused)) int x, a;
__attribute__((unused)) char *rev, *correct = NULL;

if (format[(*i) + 1] == 'r')
{
rev = va_arg(str, char *);

for (x = 0; rev[x] != '\0'; x++)
{
correct = realloc(correct, (sizeof(char) * (x + 1)));
correct[x] = rev[x];
}

for (a = x - 1; a >= 0; a--)
_putchar(correct[a]), *len = (*len) + 1;

free(correct);
*i = (*i) + 1;
}
return (*i);
}
