#include "main.h"

/**
 *pointer - handles specifiers (p)
 *@str: list of variables to replace specifiers with
 *@format: the string being printed (containing specifiers)
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: nothing
 */

int pointer(va_list str, const char *format, int *i, int *len)
{
long int add, *bin = NULL, x, a, b, val;
void *point;
char low[] = "0123456789abcdef", not[] = "0xffffffffffffffff";

if (format[(*i)] == '*')
val = va_arg(str, int);

point = va_arg(str, void *);

if (point == NULL)
nil(len);

else
{
add = (long int)point;
if (add < 0)
{
for (x = 0; not[x] != '\0'; x++)
_putchar(not[x]), *len = (*len) + 1;
}

else
{
for (x = add, a = 1; x > 0; x = (x / 16), a++)
{
bin = realloc(bin, (sizeof(long int) * (a + 1)));
bin[a] = x % 16;
}

if (format[(*i)] == '*')
width(a + 2, 'x', len, val);
else if (atoi(&(format[(*i)])) < 10 && (format[(*i) - 1] > 48 && format[(*i) - 1] < 58))
width(a + 2, 'x', len, (atoi(&(format[(*i)])) + (10 * (format[(*i) - 1] - 48))));
else if (atoi(&(format[(*i)])) < 10 && atoi(&(format[(*i)])) > 0)
width(a + 2, 'x', len, atoi(&(format[(*i)])));

_putchar('0'), _putchar('x');
*len = (*len) + 2;

for (x = a - 1; x >= 1; x--)
{
for (b = 0; low[b] != '\0'; b++)
{
if (bin[x] == b)
_putchar(low[b]), *len = (*len) + 1;
}
}
}
}
*i = (*i) + 1;

return (*i);
}


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

if (format[(*i) + 1] == 'p')
*i = pointer(str, format, i, len);

return (*i);
}
