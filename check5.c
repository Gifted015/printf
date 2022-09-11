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
__attribute__((unused)) char *rev, *rot_13, *correct = NULL;
__attribute__((unused)) char c[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
__attribute__((unused)) char e[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

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


else if (format[(*i) + 1] == 'R')
{
rot_13 = va_arg(str, char *);

for (x = 0; rot_13[x] != '\0'; x++)
{
for (a = 0; c[a] != '\0'; a++)
{
if (rot_13[x] == c[a])
{
_putchar(e[a]), *len = (*len) + 1;
break;
}
}
if (rot_13[x] != c[a])
_putchar(rot_13[x]), *len = (*len) + 1;
}

*i = (*i) + 1;
}
return (*i);
}
