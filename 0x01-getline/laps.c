#include "laps.h"

void race_state(int *id, size_t size)
{
	static int laps[128];
	static int cars[128];
	static int nc;
	int n, i;
	size_t i2;

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
	for (i2 = 0; i2 < size; i2++)
	{
		if (new_car(id[i2], cars) != 2)
		{
			laps[search_car(id[i2], cars)] = laps[search_car(id[i2], cars)] + 1;
		}
	}

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
int search_car(int id, int *cars)
{
	int i;

	i = 0;
	while ((cars[i] != -1))
	{
		if (cars[i] == id)
			return (i);
		i++;
	}
	return (-1);
}

void order_array(int *cars, int *laps, int tc)
{
	int i, j, min_idx, temp;

	(void)laps;
	for (i = 0; i < tc - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < tc; j++)
			if (cars[j] < cars[min_idx])
				min_idx = j;

		temp = cars[min_idx];
		cars[min_idx] = cars[i];
		cars[i] = temp;

		temp = laps[min_idx];
		laps[min_idx] = laps[i];
		laps[i] = temp;
	}
}
