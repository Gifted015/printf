#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("Can you print an address?\n%p\nNice!\n", (void *)0x7fff5100b6f8);
	len2 = printf("Can you print an address?\n%p\nNice!\n", (void *)0x7fff5100b6f8);
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
