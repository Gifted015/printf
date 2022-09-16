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

	len = _printf("%+ld;%+li\n%+ld;%+li\n%+ld;%+li\n", UINT_MAX, UINT_MAX, 2048, 2048, 0, 0);
	len2 = printf("%+ld;%+li\n%+ld;%+li\n%+ld;%+li\n", UINT_MAX, UINT_MAX, 2048, 2048, 0, 0);
	printf("len: %d\tlen2: %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%.d", 0);
	len2 = printf("%.d", 0);
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
