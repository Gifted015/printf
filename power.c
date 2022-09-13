#include "main.h"


/**
 *_pow: calculates 'base' raise to the power of 'power'
 *@base: the base
 *@power: the power
 *Return: the answer
 */

int _pow(int base, int power)
{
int ans = base, x;

for (x = 1; x <= power; x++)
{
ans *= ans;
}

return (ans);
}
