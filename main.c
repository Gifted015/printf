#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("%s%d bytes in %i %c%c\n", "There is ", 1024, 1, 'K', 'B');
	len2 = printf("%s%d bytes in %i %c%c\n", "There is ", 1024, 1, 'K', 'B');
	printf("len: %d\tlen2: %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%s%i bytes in %d %c%c\n", "There is ", 1024, 1, 'K', 'B');
	len2 = printf("%s%i bytes in %d %c%c\n", "There is ", 1024, 1, 'K', 'B');
	printf("len: %d\tlen2: %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
