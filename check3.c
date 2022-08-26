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
unsigned int a, b, c, d, x, *bin = NULL;
char upp[] = "0123456789ABCDEF", *words, nonprint[] = "\\x0";
words = va_arg(str, char *);
if (words == NULL)
{
null(len);
}
else
{
for (x = 0; words[x] != '\0'; x++)
{
if ((words[x] > 0 && words[x] < 32) || words[x] >= 127)
{
for (c = words[x], a = 1; c > 0; c = (c / 16), a++)
{
bin = realloc(bin, (sizeof(int) * (a + 1)));
bin[a] = c % 16;
}
for (c = a - 1; c >= 1; c--)
{
for (b = 0; upp[b] != '\0'; b++)
{
if (bin[c] == b)
{
for (d = 0; nonprint[d] != '\0'; d++)
_putchar(nonprint[d]);
_putchar(upp[b]);
*len = (*len) + 1;
}
}
}
}
else
{
_putchar(words[x]), *len = (*len) + 1;
}
}
}
*i = (*i) + 1;
return (*i);
}


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
