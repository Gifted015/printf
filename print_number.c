#include "main.h"
#include <string.h>

/**
 *n2 - helps in printing an integer
 *@n: integer
 *@len: counts the length of the number
 *Return: nothing
 */

void n2(int n, int *len)
{
if (n >= 1000000000)
{
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
*len = (*len) + 10;
}
if (n < 1000000000 && n >= 100000000)
{
_putchar (((n % 1000000000) / 100000000) + 48);
_putchar (((n % 100000000) / 10000000) + 48);
_putchar (((n % 10000000) / 1000000) + 48);
_putchar (((n % 1000000) / 100000) + 48);
_putchar (((n % 100000) / 10000) + 48);
_putchar (((n % 10000) / 1000) + 48);
_putchar (((n % 1000) / 100) + 48);
_putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 48);
*len = (*len) + 9;
}
}

/**
 *n1 - helps in printing an integer
 *@n: integer
 *@len: counts the length of the number
 *Return: nothing
 */

void n1(int n, int *len)
{
if (n < 100000000 && n >= 10000000)
{
_putchar (((n % 100000000) / 10000000) + 48);
_putchar (((n % 10000000) / 1000000) + 48);
_putchar (((n % 1000000) / 100000) + 48);
_putchar (((n % 100000) / 10000) + 48);
_putchar (((n % 10000) / 1000) + 48);
_putchar (((n % 1000) / 100) + 48);
_putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 48);
*len = (*len) + 8;
}
if (n < 10000000 && n >= 1000000)
{
_putchar (((n % 10000000) / 1000000) + 48);
_putchar (((n % 1000000) / 100000) + 48);
_putchar (((n % 100000) / 10000) + 48);
_putchar (((n % 10000) / 1000) + 48);
_putchar (((n % 1000) / 100) + 48);
_putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 48);
*len = (*len) + 7;
}
if (n < 1000000 && n >= 100000)
{
_putchar (((n % 1000000) / 100000) + 48);
_putchar (((n % 100000) / 10000) + 48);
_putchar (((n % 10000) / 1000) + 48);
_putchar (((n % 1000) / 100) + 48);
_putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 48);
*len = (*len) + 6;
}
}


/**
 *n3 - helps in printing an integer
 *@n: integer
 *@len: counts the length of the number
 *Return: nothing
 */

void n3(int n, int *len)
{
if (n < 100000 && n >= 10000)
{
_putchar (((n % 100000) / 10000) + 48);
_putchar (((n % 10000) / 1000) + 48);
_putchar (((n % 1000) / 100) + 48);
_putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 48);
*len = (*len) + 5;
}
}


/**
 *end - prints an integer
 *@n: integer
 *@len: counts the length of the number
 *Return: nothing
 */

void end(int n, int *len)
{
if (n == -2147483648)
{
_putchar('-');
n = -n - 1;
_putchar (((n % 10000000000) / 1000000000) + 48);
_putchar (((n % 1000000000) / 100000000) + 48);
_putchar (((n % 100000000) / 10000000) + 48);
_putchar (((n % 10000000) / 1000000) + 48);
_putchar (((n % 1000000) / 100000) + 48);
_putchar (((n % 100000) / 10000) + 48);
_putchar (((n % 10000) / 1000) + 48);
_putchar (((n % 1000) / 100) + 48);
_putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 49);
*len = (*len) + 11;
}
}


/**
 *print_number - prints an integer
 *@n: integer
 *@len: counts the length of the number
 *Return: nothing
 */

void print_number(int n, int *len)
{
end(n, len);
if (n < 0 && n != -2147483648)
{
_putchar ('-');
n = -n;
*len = (*len) + 1;
}
if (n >= 100000000)
n2(n, len);
if (n < 100000000 && n >= 100000)
n1(n, len);
if (n < 100000 && n >= 10000)
n3(n, len);
if (n < 10000 && n >= 1000)
{
_putchar (((n % 10000) / 1000) + 48);
_putchar (((n % 1000) / 100) + 48);
_putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 48);
*len = (*len) + 4;
}
if (n < 1000 && n >= 100)
{
_putchar (((n % 1000) / 100) + 48);
_putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 48);
*len = (*len) + 3;
}
if (n < 100 && n >= 10)
{
_putchar (((n % 100) / 10) + 48);
_putchar((n % 10) + 48);
*len = (*len) + 2;
}
if (n < 10 && n >= 0)
{
_putchar((n % 10) + 48);
*len = (*len) + 1;
}
}
