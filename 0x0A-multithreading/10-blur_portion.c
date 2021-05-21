#include "multithreading.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void gaussian_blur(const kernel_t *kernel,
			const img_t *, img_t *, size_t, int);
void _img_copy(img_t *dest, img_t const *src);
/**
 * blur_portion - blurs a portion of an image using a Gaussian Blur
 * @portion: points to a data structure
 */
void blur_portion(blur_portion_t const *portion)
{
	img_t image;
	size_t init = (portion->y * (portion->img->w)) + portion->x;
	size_t end = (portion->y + portion->h) * (portion->img->w);
	size_t x = portion->x;
	size_t rest = portion->img->w - (portion->x + portion->w);
	size_t s_kernel = portion->kernel->size - 1;
	int init_kernel = ((portion->y - s_kernel / 2) *
				portion->img->w) + portion->x - s_kernel / 2;
	_img_copy(&image, portion->img);

	for (; init < end; init += 1, x += 1, init_kernel += 1)
	{

		if (x == portion->x + portion->w)
		{
			init += rest + (portion->x);
			x = portion->x;
			init_kernel += rest + portion->x;
		}
		if (init >= end)
			break;
		gaussian_blur(portion->kernel, &image,
				portion->img_blur, init, init_kernel);

	}
	free(image.pixels);
}

/**
 * gaussian_blur - blurs a portion of an image using a Gaussian Blur
 * @kernel: points to the kernel
 * @img: points to the image
 * @blur: image blured
 * @pixel_n: target pixel
 * @init_kernel: pointer to initial pixel of the img
 */
void gaussian_blur(const kernel_t *kernel, const img_t *img,
			img_t *blur, size_t pixel_n, int init_kernel)
{
	size_t i, j;
	float sum_kernel = 0;
	float avg_g = 0;
	float avg_r = 0;
	float avg_b = 0;
	float w;
	(void) pixel_n;
	(void) blur;
	for (i = 0; i < kernel->size; i++)
	{
		for (j = 0; j < kernel->size; j++, init_kernel += 1)
		{
			w = kernel->matrix[i][j];
			if (init_kernel < 0 || init_kernel > (int)(img->w * img->h))
				continue;
			avg_g += (img->pixels[init_kernel].g * w);
			avg_r += (img->pixels[init_kernel].r * w);
			avg_b += (img->pixels[init_kernel].b * w);

			sum_kernel += w;
		}
		init_kernel += (img->w - kernel->size);
	}

	avg_g = (int)(avg_g / (sum_kernel));
	avg_r = (int)(avg_r / (sum_kernel));
	avg_b = (int)(avg_b / (sum_kernel));
	blur->pixels[pixel_n].r = avg_r;
	blur->pixels[pixel_n].b = avg_b;
	blur->pixels[pixel_n].g = avg_g;

	/*img->pixels[pixel_n].r = avg_r;*/
	/*img->pixels[pixel_n].b = avg_b;*/
	/*img->pixels[pixel_n].g = avg_g;*/
}
/**
 * _img_copy - make a copy of the original image
 * @dest: the destination image
 * @src: the source image
 */
void _img_copy(img_t *dest, img_t const *src)
{
	size_t nb_pixels = src->w * src->h;

	dest->w = src->w;
	dest->h = src->h;
	dest->pixels = malloc(nb_pixels * sizeof(pixel_t));
	memcpy(dest->pixels, src->pixels, nb_pixels * sizeof(pixel_t));
}
