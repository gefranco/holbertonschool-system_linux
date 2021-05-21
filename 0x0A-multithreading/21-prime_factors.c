#include "multithreading.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * prime_factors - factorizes a number into a list of prime factors
 * @s: Number as string
 * Return: List of prime factors
 */
list_t *prime_factors(char const *s)
{
	list_t *list = malloc(sizeof(list_t));
	unsigned long num = strtoul(s, NULL, 10);
	unsigned long *p_num = malloc(sizeof(unsigned long));
	unsigned long pf = 2;
	*p_num = pf;

	list_init(list);

	list_add(list, (void *)p_num);

	while (pf * pf <= num)
	{
		while (num % pf == 0)
		{
			p_num = malloc(sizeof(unsigned long));
			*p_num = pf;
			list_add(list, (void *)p_num);
			num = num / pf;
		}
		pf += 1;
	}
	if (num > 1)
	{
		p_num = malloc(sizeof(unsigned long));
		*p_num = num;
		list_add(list, (void *)p_num);
	}

	return (list);
}
