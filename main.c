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

        len = _printf("%h\n");
	len2 = printf("%h\n");
	printf("len: %d\tlen2: %d\n", len, len2);
        len = _printf("\n%l\n");
	len2 = printf("%l\n");
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
