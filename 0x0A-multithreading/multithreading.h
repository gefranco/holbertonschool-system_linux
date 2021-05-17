#ifndef _MULTI_THREAD_
#define _MULTI_THREAD_
#include <stddef.h>
#include <stdint.h>
#include <pthread.h>
#include "list.h"
pthread_mutex_t lock;
typedef struct pixel_s
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
} pixel_t;

typedef struct img_s
{
	size_t w;
	size_t h;
	pixel_t *pixels;
} img_t;

typedef struct kernel_s
{
	size_t size;
	float **matrix;
} kernel_t;

typedef struct blur_portion_s
{
	img_t const *img;
	img_t *img_blur;
	size_t x;
	size_t y;
	size_t w;
	size_t h;
	kernel_t const *kernel;
} blur_portion_t;
void *thread_entry(void *arg);
int tprintf(char const *format, ...);
void blur_portion(blur_portion_t const *portion);
void blur_image(img_t *img_blur, img_t const *img, kernel_t const *kernel);
list_t *prime_factors(char const *s);

void begin (void) __attribute__((constructor));
void end (void) __attribute__((destructor));
#endif
