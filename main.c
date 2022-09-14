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

	len = _printf("%-6s%c", "Best", '\n');
	len2 = printf("%-6s%c", "Best", '\n');
	printf("len: %d\tlen2: %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%-*s%-*c", 16, "Best", 1, '\n');
	len2 = printf("%-*s%-*c", 16, "Best", 1, '\n');
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
