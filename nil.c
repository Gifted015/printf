#include "main.h"

/**
 *nil - prints the string "(nil)"
 *@len: used to add the lenght of "nil" to
 *the lenght of string originally printed
 *Return: nothing
 */

void nil(__attribute__((unused)) int *len)
{
int x;
char empty[] = "(nil)";

for (x = 0; empty[x] != '\0'; x++)
{
_putchar(empty[x]);
*len = (*len) + 1;
}
}
