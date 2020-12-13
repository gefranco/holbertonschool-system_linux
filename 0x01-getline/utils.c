#include "laps.h"
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
	int i, j, min_idx;

	(void)laps;
	for (i = 0; i < tc - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < tc; j++)
			if (cars[j] < cars[min_idx])
				min_idx = j;

		swap(&cars[min_idx], &cars[i]);
		swap(&laps[min_idx], &laps[i]);
	}
}

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
