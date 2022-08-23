#include "main.h"
#include <string.h>

/**
 *print_contd - prints an integer
 *@n: integer
 *@len: counts the length of the number
 *Return: nothing
 */

void print_contd(long int n, int *len)
{
if (n < 100000000000 && n >= 10000000000)
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
_putchar((n % 10) + 48);
*len = (*len) + 10;
}
}
