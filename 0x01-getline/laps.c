#include "laps.h"

void race_state(int *id, size_t size)
{
	static int laps[100];

	static int cars[100];
	static int nc;
	int n;

	if (!cars[0])
	{
		nc = 0;
		cars[size] = -1;
		addcars(id, cars, laps, nc, size);
		nc = size;
	}
	else
	{
		n = addcars(id, cars, laps, nc, size);
		nc = nc + n;

	}
	order_array(cars, laps, nc);
	count_laps(id, cars, laps, size);
	print_state(cars, laps);
}

int count_laps(int *id, int *cars, int *laps, size_t size)
{
	size_t i;

	i = 0;
	for (i = 0; i < size; i++)
	{
		if (new_car(id[i], cars) != 2)
		{
			laps[search_car(id[i], cars)] = laps[search_car(id[i], cars)] + 1;
		}
	}
	return (0);
}
void print_state(int *cars, int *laps)
{
	int i;

	i = 0;
	printf("Race state:\n");
	while ((cars[i] != -1))
	{
		printf("Car %d [%d laps]\n", cars[i], laps[i]);
		i++;
	}
}

int addcars(int *id, int *cars, int *laps, int nc, size_t size)
{
	size_t i;
	int j, t;

	j = nc;
	i = 0;
	t = 0;
	for (i = 0; i < size; i++)
	{
		if (new_car(id[i], cars))
		{
			cars[j] = id[i];
			laps[j] = -1;
			cars[j + 1] = -1;
			printf("Car %d joined the race\n", cars[j]);
			j++;
			t++;
		}
	}

	return (t);
}

int new_car(int id, int *cars)
{
	int i;

	i = 0;

	while ((cars[i] != -1))
	{
		if (cars[i] == id)
			return (0);
		i++;
	}
	return (2);
}
