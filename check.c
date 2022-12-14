#include "main.h"

/**
 *word - handles string and character specifiers
 *@str: list of variables to replace specifiers with
 *@format: the string being printed (containing specifiers)
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: i
 */

int word(va_list str, const char *format, int *i, int *len)
{
__attribute__((unused)) int x, y, val;
__attribute__((unused)) char *words, chr;


if (format[(*i) + 1] == 'c')
{
if (format[(*i)] == '*')
val = va_arg(str, int);

chr = va_arg(str, int);
if (format[(*i) - 1] != '-')
{
if (format[(*i) - 2] != '-')
{
if (format[(*i) - 1] == '.' || format[(*i) - 1] == '0')
{
if (format[(*i)] == '*')
prec(1, 'c', len, val);
else
prec(1, 'c', len, atoi(&(format[(*i)])));
}
else if (format[(*i)] == '*')
width(1, 'c', len, val);
else if (atoi(&(format[(*i)])) < 10 && format[(*i) - 1] == '1')
{
if (format[(*i) - 2] == '.')
width(1, 'c', len, 1);
else
width(1, 'c', len, atoi(&(format[(*i)])) + 10);
}
else if (atoi(&(format[(*i)])) < 10 && atoi(&(format[(*i)])) > 0)
width(1, 'c', len, atoi(&(format[(*i)])));
}
}
_putchar(chr);
*len = (*len) + 1;
if (format[(*i) - 1] == '-' || format[(*i) - 2] == '-')
{
if (atoi(&(format[(*i)])) < 10 && format[(*i) - 1] == '1')
width(1, 'c', len, atoi(&(format[(*i)])) + 10);
else if (format[(*i)] == '*')
width(1, 'c', len, val);
else
width(1, 'c', len, atoi(&(format[(*i)])));
}
*i = (*i) + 1;
}


else if (format[(*i) + 1] == 's')
{
if (format[(*i)] == '*')
val = va_arg(str, int);

words = va_arg(str, char *);

if (words == NULL)
{
null(len);
}

else
{
for (y = 0; words[y] != '\0'; y++)
{ }
if (format[(*i) - 1] != '-')
{
if (format[(*i) - 2] != '-')
{
if (format[(*i) - 1] == '.' || format[(*i) - 1] == '0')
{
if (format[(*i)] == '*')
y = prec(y, 's', len, val);
else
y = prec(y, 's', len, atoi(&(format[(*i)])));
}
else if (format[(*i)] == '*')
width(y, 's', len, val);
else if (atoi(&(format[(*i)])) < 10 && format[(*i) - 1] == '1')
{
if (format[(*i) - 2] == '.')
width(y, 's', len, y);
else
width(y, 's', len, atoi(&(format[(*i)])) + 10);
}
else if (atoi(&(format[(*i)])) < 10 && atoi(&(format[(*i)])) > 0)
width(y, 's', len, atoi(&(format[(*i)])));
}
}
for (x = 0; x < y; x++)
{
_putchar(words[x]);
*len = (*len) + 1;
}
if (format[(*i) - 1] == '-' || format[(*i) - 2] == '-')
{
if (atoi(&(format[(*i)])) < 10 && format[(*i) - 1] == '1')
width(y, 's', len, atoi(&(format[(*i)])) + 10);
else if (format[(*i)] == '*')
width(y, 's', len, val);
else
width(y, 's', len, atoi(&(format[(*i)])));
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
 *Return: i
 */

int numbers(va_list str, const char *format, int *i, int *len)
{
__attribute__((unused)) unsigned long int num;
__attribute__((unused)) long int numelse, val;

if (format[(*i) + 1] == '+')
{
if (format[(*i) + 2] == 'd' || format[(*i) + 2] == 'i')
*i = (*i) + 1;
else
*i = (*i) + 2;

if (format[(*i) + 1] == ' ')
*i = (*i) + 1;
}

if (format[(*i)] == ' ')
{
if (format[(*i) + 1] == 'd' || format[(*i) + 1] == 'i')
{ }
else
*i = (*i) + 1;
}

if (format[(*i)] == '*')
{
val = va_arg(str, int);

if (val == '\0' && (format[(*i)] == '.' || format[(*i)] == '0'))
{
*i = (*i) + 1;

return (*i);
}
}

if (format[(*i)] == 'l')
num = va_arg(str, unsigned long int);
else
numelse = va_arg(str, int);

if (format[(*i) - 1] == '+' || format[(*i)] == '+')
{
if (format[(*i)] == 'l')
_putchar('+'), *len = (*len) + 1;
else
{
if (numelse >= 0)
_putchar('+'), *len = (*len) + 1;
}
}

if (format[(*i) - 1] == ' ' || format[(*i)] == ' ')
{
if (format[(*i)] == 'l')
_putchar(' '), *len = (*len) + 1;
else
{
if (numelse >= 0)
_putchar(' '), *len = (*len) + 1;
}
}

if (format[(*i)] != 'l' || format[(*i)] != 'h')
{
if (format[(*i) - 1] == '.' || format[(*i) - 1] == '0')
{
if (format[(*i)] == '*')
{
if (val == '0' && numelse == 0)
*i = (*i) + 1;
numelse = prec(numelse, 'n', len, val);
}
else if (format[(*i)] == '0' && numelse == 0)
*i = (*i) + 1;
else
numelse = prec(numelse, 'n', len, atoi(&(format[(*i)])));
}
else if (format[(*i)] == '.' && numelse == 0)
*i = (*i) + 1;
else if (format[(*i) - 1] == '-')
width(numelse, '-', len, atoi(&(format[(*i)]))), *i = (*i) + 1;
else if (format[(*i)] == '*')
width(numelse, 'n', len, val);
else if (atoi(&(format[(*i)])) < 10 && format[(*i) - 1] == '1')
width(numelse, 'n', len, atoi(&(format[(*i)])) + 10);
else if (atoi(&(format[(*i)])) < 10 && atoi(&(format[(*i)])) > 0)
width(numelse, 'n', len, atoi(&(format[(*i)])));
}

if (format[(*i) + 1] == 'd' || format[(*i) + 1] == 'i')
{
if (format[(*i)] == 'l')
print_number(num, len);
else
print_number(numelse, len);
*i = (*i) + 1;
}

return (*i);
}


/**
 *binary - handles binary specifiers
 *@str: list of variables to replace specifiers with
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: i
 */

int binary(va_list str, int *i, int *len)
{
unsigned int a, x, test, *bin = NULL;
test = va_arg(str, int);

if (test == 0)
{
print_number(0, len);
}

else
{
for (x = test, a = 1; x > 0; x = (x / 2), a++)
{
bin = realloc(bin, (sizeof(int) * (a + 1)));
bin[a] = x % 2;
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
 *check - handles specifiers
 *@str: list of variables to replace specifiers with
 *@format: the string being printed (containing specifiers)
 *@i: position of specifier indicator (%) in format
 *@len: used in counting the number characters being printed
 *Return: i
 */

int check(va_list str, const char *format, int *i, int *len)
{
__attribute__((unused)) char spec[18] = "+ #lh*", first[] = "uoxX";
 __attribute__((unused)) char second[] = "csdib%", last[] = ".0-";
__attribute__((unused)) char third[] = "Sp", final[] = "rR";
__attribute__((unused)) int k, d = 49;

for (k = 6; k <= 14; k++)
spec[k] = d, d++;

for (k = 0; k < 18; k++)
{
if (format[(*i) + 1] == first[k] || format[(*i) + 1] == last[k])
break;
else if (format[(*i) + 1] == second[k] || format[(*i) + 1] == spec[k])
break;
else if (format[(*i) + 1] == third[k] || format[(*i) + 1] == final[k])
break;
}
if (format[(*i) + 1] == final[k])
*i = check6(str, format, i, len);

else if (format[(*i) + 1] == last[k])
*i = check5(str, format, i, len);

else if (format[(*i) + 1] == spec[k])
*i = check4(str, format, i, len);

else if (format[(*i) + 1] == first[k])
*i = check2(str, format, i, len);

else if (format[(*i) + 1] == second[k])
*i = checker(str, format, i, len);

else if (format[(*i) + 1] == third[k])
*i = check3(str, format, i, len);

else
{
if (format[(*i) + 1] == '\0')
*len = -1;
else
{
if (format[(*i)] == 'l' || format[(*i)] == 'h')
_putchar(format[(*i - 1)]);
else
_putchar(format[(*i)]);
*len = (*len) + 1;
}
}
return (*i);
}
