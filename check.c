#include "main.h"

/**
 *word - handles string and character specifiers
 *@str: list of variables to replace specifiers with
 *@format: the string being printed (containing specifiers)
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: nothing
 */

int word(va_list str, const char *format, int *i, int *len)
{
__attribute__((unused)) int x;
__attribute__((unused)) char *words, chr;


if (format[(*i) + 1] == 'c')
{
chr = va_arg(str, int);
_putchar(chr);
*len = (*len) + 1;
*i = (*i) + 1;
}


else if (format[(*i) + 1] == 's')
{
words = va_arg(str, char *);

if (words == NULL)
{
null(len);
}

else
{
for (x = 0; words[x] != '\0'; x++)
{
_putchar(words[x]);
*len = (*len) + 1;
}
}
*i = (*i) + 1;
}
return (*i);
}


/**
 *numbers - handles digits and integers specifiers
 *@str: list of variables to replace specifiers with
 *@format: the string being printed (containing specifiers)
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: nothing
 */

int numbers(va_list str, const char *format, int *i, int *len)
{
__attribute__((unused)) int in, dec;


if (format[(*i) + 1] == 'd')
{
dec = va_arg(str, int);
print_number(dec, len);
*i = (*i) + 1;
}


else if (format[(*i) + 1] == 'i')
{
in = va_arg(str, int);
print_number(in, len);
*i = (*i) + 1;
}
return (*i);
}


/**
 *binary - handles binary specifiers
 *@str: list of variables to replace specifiers with
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: nothing
 */

int binary(va_list str, int *i, int *len)
{
int a, x, *bin;

for (x = va_arg(str, int), a = 0; x > 0; x = (x / 2), a++)
{
bin = realloc(bin, (sizeof(int) * (a + 1)));
bin[a] = x % 2;
}

for (x = a - 1; x >= 0; x--)
print_number(bin[x], len);

free(bin);
*i = (*i) + 1;
return (*i);
}


/**
 *check - handles specifiers
 *@str: list of variables to replace specifiers with
 *@format: the string being printed (containing specifiers)
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: nothing
 */

int check(va_list str, const char *format, int *i, int *len)
{
if (format[(*i) + 1] == 'c' || format[(*i) + 1] == 's')
*i = word(str, format, i, len);


else if (format[(*i) + 1] == 'd' || format[(*i) + 1] == 'i')
*i = numbers(str, format, i, len);


else if (format[(*i) + 1] == 'b')
*i = binary(str, i, len);


else if (format[(*i) + 1] == '%')
{
_putchar(format[(*i)]);
*i = (*i) + 1;
*len = (*len) + 1;
}

else
{
if (format[(*i) + 1] == '\0')
*len = -1;

else
{
_putchar(format[(*i)]);
*len = (*len) + 1;
}
}
return (*i);
}
