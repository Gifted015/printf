#include <limits.h>
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
char *s;
	int i;
	int len, len2;

	s = malloc(1020);
	i = 0;
	while (i < 1019)
	{
		s[i] = 'A';
		i++;
	}
	s[i] = 0;
	len = _printf("%s%b\n\n", s, INT_MAX);
	len2 = printf("%s%s\n", s, "1111111111111111111111111111111");
	fflush(stdout);
	printf("len: %d\tlen2: %d\n", len, len2);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
