#include "main.h"
#include <string.h>


/**
 *print4 - prints an integer
 *@n: integer
 *@len: counts the length of the number
 *Return: nothing
 */

void print4(unsigned long int n, int *len)
{
if (n >= 1000000000000000000)
{
_putchar ((n / 1000000000000000000) + 48);
_putchar (((n % 1000000000000000000) / 100000000000000000) + 48);
_putchar (((n % 100000000000000000) / 10000000000000000) + 48);
_putchar (((n % 10000000000000000) / 1000000000000000) + 48);
_putchar (((n % 1000000000000000) / 100000000000000) + 48);
_putchar (((n % 100000000000000) / 10000000000000) + 48);
_putchar (((n % 10000000000000) / 1000000000000) + 48);
_putchar (((n % 1000000000000) / 100000000000) + 48);
_putchar (((n % 100000000000) / 10000000000) + 48);
_putchar (((n % 10000000000) / 1000000000) + 48);
_putchar (((n % 1000000000) / 100000000) + 48);
_putchar (((n % 100000000) / 10000000) + 48);
_putchar (((n % 10000000) / 1000000) + 48);
_putchar (((n % 1000000) / 100000) + 48);
_putchar (((n % 100000) / 10000) + 48);
_putchar (((n % 10000) / 1000) + 48);
_putchar (((n % 1000) / 100) + 48), _putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 48), *len = (*len) + 19;
}
else if (n < 1000000000000000000 && n >= 100000000000000000)
{
_putchar (((n % 1000000000000000000) / 100000000000000000) + 48);
_putchar (((n % 100000000000000000) / 10000000000000000) + 48);
_putchar (((n % 10000000000000000) / 1000000000000000) + 48);
_putchar (((n % 1000000000000000) / 100000000000000) + 48);
_putchar (((n % 100000000000000) / 10000000000000) + 48);
_putchar (((n % 10000000000000) / 1000000000000) + 48);
_putchar (((n % 1000000000000) / 100000000000) + 48);
_putchar (((n % 100000000000) / 10000000000) + 48);
_putchar (((n % 10000000000) / 1000000000) + 48);
_putchar (((n % 1000000000) / 100000000) + 48);
_putchar (((n % 100000000) / 10000000) + 48);
_putchar (((n % 10000000) / 1000000) + 48);
_putchar (((n % 1000000) / 100000) + 48);
_putchar (((n % 100000) / 10000) + 48), _putchar (((n % 10000) / 1000) + 48);
_putchar (((n % 1000) / 100) + 48), _putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 48), *len = (*len) + 18;
}
}


/**
 *print3 - prints an integer
 *@n: integer
 *@len: counts the length of the number
 *Return: nothing
 */

void print3(unsigned long int n, int *len)
{
if (n < 100000000000000000 && n >= 10000000000000000)
{
_putchar (((n % 100000000000000000) / 10000000000000000) + 48);
_putchar (((n % 10000000000000000) / 1000000000000000) + 48);
_putchar (((n % 1000000000000000) / 100000000000000) + 48);
_putchar (((n % 100000000000000) / 10000000000000) + 48);
_putchar (((n % 10000000000000) / 1000000000000) + 48);
_putchar (((n % 1000000000000) / 100000000000) + 48);
_putchar (((n % 100000000000) / 10000000000) + 48);
_putchar (((n % 10000000000) / 1000000000) + 48);
_putchar (((n % 1000000000) / 100000000) + 48);
_putchar (((n % 100000000) / 10000000) + 48);
_putchar (((n % 10000000) / 1000000) + 48);
_putchar (((n % 1000000) / 100000) + 48);
_putchar (((n % 100000) / 10000) + 48);
_putchar (((n % 10000) / 1000) + 48);
_putchar (((n % 1000) / 100) + 48);
_putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 48), *len = (*len) + 17;
}
else if (n < 100000000000000000 && n >= 10000000000000000)
{
_putchar (((n % 100000000000000000) / 10000000000000000) + 48);
_putchar (((n % 10000000000000000) / 1000000000000000) + 48);
_putchar (((n % 1000000000000000) / 100000000000000) + 48);
_putchar (((n % 100000000000000) / 10000000000000) + 48);
_putchar (((n % 10000000000000) / 1000000000000) + 48);
_putchar (((n % 1000000000000) / 100000000000) + 48);
_putchar (((n % 100000000000) / 10000000000) + 48);
_putchar (((n % 10000000000) / 1000000000) + 48);
_putchar (((n % 1000000000) / 100000000) + 48);
_putchar (((n % 100000000) / 10000000) + 48);
_putchar (((n % 10000000) / 1000000) + 48);
_putchar (((n % 1000000) / 100000) + 48);
_putchar (((n % 100000) / 10000) + 48);
_putchar (((n % 10000) / 1000) + 48);
_putchar (((n % 1000) / 100) + 48);
_putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 48), *len = (*len) + 16;
}
}


/**
 *print2 - prints an integer
 *@n: integer
 *@len: counts the length of the number
 *Return: nothing
 */

void print2(unsigned long int n, int *len)
{
if (n < 10000000000000000 && n >= 1000000000000000)
{
_putchar (((n % 10000000000000000) / 1000000000000000) + 48);
_putchar (((n % 1000000000000000) / 100000000000000) + 48);
_putchar (((n % 100000000000000) / 10000000000000) + 48);
_putchar (((n % 10000000000000) / 1000000000000) + 48);
_putchar (((n % 1000000000000) / 100000000000) + 48);
_putchar (((n % 100000000000) / 10000000000) + 48);
_putchar (((n % 10000000000) / 1000000000) + 48);
_putchar (((n % 1000000000) / 100000000) + 48);
_putchar (((n % 100000000) / 10000000) + 48);
_putchar (((n % 10000000) / 1000000) + 48);
_putchar (((n % 1000000) / 100000) + 48);
_putchar (((n % 100000) / 10000) + 48);
_putchar (((n % 10000) / 1000) + 48);
_putchar (((n % 1000) / 100) + 48);
_putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 48);
*len = (*len) + 15;
}
else if (n < 1000000000000000 && n >= 100000000000000)
{
_putchar (((n % 1000000000000000) / 100000000000000) + 48);
_putchar (((n % 100000000000000) / 10000000000000) + 48);
_putchar (((n % 10000000000000) / 1000000000000) + 48);
_putchar (((n % 1000000000000) / 100000000000) + 48);
_putchar (((n % 100000000000) / 10000000000) + 48);
_putchar (((n % 10000000000) / 1000000000) + 48);
_putchar (((n % 1000000000) / 100000000) + 48);
_putchar (((n % 100000000) / 10000000) + 48);
_putchar (((n % 10000000) / 1000000) + 48);
_putchar (((n % 1000000) / 100000) + 48);
_putchar (((n % 100000) / 10000) + 48);
_putchar (((n % 10000) / 1000) + 48);
_putchar (((n % 1000) / 100) + 48);
_putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 48);
*len = (*len) + 14;
}
}

/**
 *print1 - prints an integer
 *@n: integer
 *@len: counts the length of the number
 *Return: nothing
 */

void print1(unsigned long int n, int *len)
{
if (n < 100000000000000 && n >= 10000000000000)
{
_putchar (((n % 100000000000000) / 10000000000000) + 48);
_putchar (((n % 10000000000000) / 1000000000000) + 48);
_putchar (((n % 1000000000000) / 100000000000) + 48);
_putchar (((n % 100000000000) / 10000000000) + 48);
_putchar (((n % 10000000000) / 1000000000) + 48);
_putchar (((n % 1000000000) / 100000000) + 48);
_putchar (((n % 100000000) / 10000000) + 48);
_putchar (((n % 10000000) / 1000000) + 48);
_putchar (((n % 1000000) / 100000) + 48);
_putchar (((n % 100000) / 10000) + 48);
_putchar (((n % 10000) / 1000) + 48);
_putchar (((n % 1000) / 100) + 48);
_putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 48);
*len = (*len) + 13;
}
else if (n < 10000000000000 && n >= 1000000000000)
{
_putchar (((n % 10000000000000) / 1000000000000) + 48);
_putchar (((n % 1000000000000) / 100000000000) + 48);
_putchar (((n % 100000000000) / 10000000000) + 48);
_putchar (((n % 10000000000) / 1000000000) + 48);
_putchar (((n % 1000000000) / 100000000) + 48);
_putchar (((n % 100000000) / 10000000) + 48);
_putchar (((n % 10000000) / 1000000) + 48);
_putchar (((n % 1000000) / 100000) + 48);
_putchar (((n % 100000) / 10000) + 48);
_putchar (((n % 10000) / 1000) + 48);
_putchar (((n % 1000) / 100) + 48);
_putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 48);
*len = (*len) + 12;
}
}

/**
 *print_contd - prints an integer
 *@n: integer
 *@len: counts the length of the number
 *Return: nothing
 */

void print_contd(unsigned long int n, int *len)
{
if (n >= 1000000000000000000)
print4(n, len);
else if (n < 1000000000000000000 && n >= 10000000000000000)
print3(n, len);
else if (n < 1000000000000000 && n >= 100000000000000)
print2(n, len);
else if (n < 100000000000000 && n >= 1000000000000)
print1(n, len);

else if (n < 1000000000000 && n >= 100000000000)
{
_putchar (((n % 1000000000000) / 100000000000) + 48);
_putchar (((n % 100000000000) / 10000000000) + 48);
_putchar (((n % 10000000000) / 1000000000) + 48);
_putchar (((n % 1000000000) / 100000000) + 48);
_putchar (((n % 100000000) / 10000000) + 48);
_putchar (((n % 10000000) / 1000000) + 48);
_putchar (((n % 1000000) / 100000) + 48);
_putchar (((n % 100000) / 10000) + 48);
_putchar (((n % 10000) / 1000) + 48);
_putchar (((n % 1000) / 100) + 48);
_putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 48), *len = (*len) + 11;
}
else if (n < 100000000000 && n >= 10000000000)
{
_putchar (((n % 100000000000) / 10000000000) + 48);
_putchar (((n % 10000000000) / 1000000000) + 48);
_putchar (((n % 1000000000) / 100000000) + 48);
_putchar (((n % 100000000) / 10000000) + 48);
_putchar (((n % 10000000) / 1000000) + 48);
_putchar (((n % 1000000) / 100000) + 48);
_putchar (((n % 100000) / 10000) + 48);
_putchar (((n % 10000) / 1000) + 48);
_putchar (((n % 1000) / 100) + 48);
_putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 48), *len = (*len) + 10;
}
}
