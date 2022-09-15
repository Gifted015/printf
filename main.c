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

	len = _printf("%*u\n%*u\n", 6, 1024, 6, 1024984020);
	len2 = printf("%*u\n%*u\n", 6, 1024, 6, 1024984020);
	printf("len: %d\tlen2: %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%*o\n%*o\n", 6, 1024, 6, 1024984020);
	len2 = printf("%*o\n%*o\n", 6, 1024, 6, 1024984020);
	printf("len: %d\tlen2: %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%*x\n%*x\n", 6, 1024, 6, 1024984020);
	len2 = printf("%*x\n%*x\n", 6, 1024, 6, 1024984020);
	printf("len: %d\tlen2: %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%*X\n%*X\n", 6, 1024, 6, 1024984020);
	len2 = printf("%*X\n%*X\n", 6, 1024, 6, 1024984020);
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
