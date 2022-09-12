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

	len = _printf("The %s value of an unsigned%c%c%c is %u\n", "max", 'i', 'n', 't', UINT_MAX);
	len2 = printf("The %s value of an unsigned%c%c%c is %u\n", "max", 'i', 'n', 't', UINT_MAX);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("The %s value of an unsigned%c%c%c is %o\n", "max", 'i', 'n', 't', UINT_MAX);
	len2 = printf("The %s value of an unsigned%c%c%c is %o\n", "max", 'i', 'n', 't', UINT_MAX);
	printf("len: %d\tlen2: %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("The %s value of an unsigned%c%c%c is %x\n", "max", 'i', 'n', 't', UINT_MAX);
	len2 = printf("The %s value of an unsigned%c%c%c is %x\n", "max", 'i', 'n', 't', UINT_MAX);
	printf("len: %d\tlen2: %d\n", len, len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("The %s value of an unsigned%c%c%c is %X\n", "max", 'i', 'n', 't', UINT_MAX);
	len2 = printf("The %s value of an unsigned%c%c%c is %X\n", "max", 'i', 'n', 't', UINT_MAX);
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
