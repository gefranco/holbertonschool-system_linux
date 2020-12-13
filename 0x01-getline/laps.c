#include "laps.h"
/**
 * race_state - keeps track of the number of laps made by the cars
 * @id: array cars ids
 * @size: size of the array
 *
 * Return: Nothing.
 */
void race_state(int *id, size_t size)
{
	static int laps[128];
	static int cars[128];
	static int nc;
	int n, i;
	size_t i2;

	if (size == 0)
		return;
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
/**
 * addcars - add new id cars to cars array
 * @id: array cars ids
 * @cars: array of cars in the 'race'
 * @laps: array of laps made by cars
 * @nc: number of cars
 * @size: size of the id array
 *
 * Return: total of cars added
 */
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
/**
 * new_car - check if id car is not added in cars
 * @id: id of car to check
 * @cars: array of cars in the 'race'
 *
 * Return: 0 if car is  added, 2 if not.
 */
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
/**
 * search_car - search the car position's in the array
 * @id: car id's to be found
 * @cars: array of cars in the 'race'
 *
 * Return: the position car in the array
 */
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
/**
 * order_array - order the array of cars in ascend order
 * @cars: array of cars in the 'race'
 * @laps: array of laps made by cars
 * @tc: number of cars
 *
 * Return: nothing
 */
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
