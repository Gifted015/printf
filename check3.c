#include "main.h"

/**
 *wordhex - handles specifiers (S)
 *@str: list of variables to replace specifiers with
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: nothing
 */

int wordhex(va_list str, int *i, int *len)
{
unsigned int a, b, c, d = 3, x, *bin = NULL;
char upp[] = "0123456789ABCDEF", *words, nonprint[5] = "\\x0";
words = va_arg(str, char *);
if (words == NULL)
null(len);
else
{
for (x = 0; words[x] != '\0'; x++)
{
if ((words[x] > 0 && words[x] < 32) || words[x] >= 127)
{
for (c = words[x], a = 1; c > 0; c = (c / 16), a++)
{
bin = realloc(bin, (sizeof(int) * (a + 1)));
bin[a] = c % 16; }
for (c = a - 1; c > 0; c--)
{
nonprint[2] = '0';
for (b = 0; upp[b] != 0; b++)
{
if (bin[c] == b)
{
nonprint[d] = upp[b];
if (a == 3)
d = 4;
}
}
}
if (d == 4)
{
nonprint[2] = nonprint[3];
nonprint[3] = nonprint[4], nonprint[4] = '\0'; }
for (b = 0; b <= 3; b++)
_putchar(nonprint[b]), *len = (*len) + 1;
d = 3; }
else
_putchar(words[x]), *len = (*len) + 1;
}
}
*i = (*i) + 1;
return (*i); }


/**
 *check3 - handles specifiers (S)
 *@str: list of variables to replace specifiers with
 *@format: the string being printed (containing specifiers)
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: nothing
 */

int check3(va_list str, const char *format, int *i, int *len)
{
if (format[(*i) + 1] == 'S')
*i = wordhex(str, i, len);

return (*i);
}
