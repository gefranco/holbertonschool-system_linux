#ifndef LAPS_H
#define LAPS_H
#include <stdio.h>
#include <stdlib.h>

void race_state(int *id, size_t size);
int addcars(int *id, int *cars,int *laps, int nc, size_t size);
int new_car(int id, int *cars);
int count_laps(int *, int *cars, int *laps,size_t size);
void print_state(int *cars, int *laps);
int search_car(int id,int *cars);
void order_array(int *cars, int *laps, int tc);
void swap(int* xp, int* yp);
#endif
