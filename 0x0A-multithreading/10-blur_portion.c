#include "multithreading.h"
#include <stdio.h>
void gaussian_blur(const kernel_t *kernel, const img_t *, img_t *, size_t, size_t);
/**
 * blur_portion - blurs a portion of an image using a Gaussian Blur
 * @portion: points to a data structure
 */
void blur_portion(blur_portion_t const *portion)
{
	/*size_t avg;*/

	size_t init = (portion->y * portion->img->w) + portion->x;
	size_t end = init + (portion->w * portion->h);
	size_t x = portion->x;
	/*size_t exe_x = portion->img->w - (portion->x + portion->w);*/

	/*size_t rest = portion->img->w - (portion->x + portion->w);*/
	size_t rest = portion->img->w - (portion->x);
	/*size_t init_kernel = init - (portion->img->w * portion->kernel->size);*/
	size_t init_kernel = ((portion->y - portion->kernel->size) * portion->img->w) + portion->x;
	
	printf("init_kernel %lu\n", init_kernel);
	printf("init %lu\n", init);
	printf("portion x %lu\n", portion->x);
	printf("init_kernel %lu\n", init_kernel);

	for (; init < end; init += 1, x += 1, init_kernel += 1)
	{
		gaussian_blur(portion->kernel, portion->img, portion->img_blur, init, init_kernel);
		
		/*avg = (portion->img_blur->pixels[init].r +
		portion->img_blur->pixels[init].g +
		portion->img_blur->pixels[init].b) / 3;
		*/
		/*printf("%lu\n", avg);*/
		/*portion->img_blur->pixels[init].r = avg;*/
		
		/*portion->img_blur->pixels[init].g = avg;
		portion->img_blur->pixels[init].b = avg;
		*/
		if (x == portion->w)
		{
			init += rest;
			x = portion->x;
			
			init_kernel +=rest;
		}
	}
}


void gaussian_blur(const kernel_t *kernel, const img_t *img, img_t *blur, size_t pixel_n, size_t init_kernel)
{
	size_t i,j;
	/*size_t reset = 0;*/
	int avg_g = 0;

	int avg_r = 0;
	int avg_b = 0;
	for (i = 0; i < kernel->size; i++)
	{
		for (j = 0; j < kernel->size; j++, init_kernel +=1)
		{
			/*printf("[%f", kernel->matrix[i][j]);*/
			avg_g += (img->pixels[init_kernel].g * kernel->matrix[i][j]);
			avg_r += (img->pixels[init_kernel].r * kernel->matrix[i][j]);
			avg_b += (img->pixels[init_kernel].b * kernel->matrix[i][j]);
		}
		/*printf("\n");*/
		init_kernel += (img->w - kernel->size);
		/*blur->pixels[init_kernel].g = 255;
		blur->pixels[init_kernel].b = 255;
		blur->pixels[init_kernel].r = 255;
		*/	
		printf("**%lu\n", init_kernel);
		
	}
	
	avg_g = avg_g / (kernel->size * kernel->size);
	avg_r = avg_r / (kernel->size * kernel->size);
	avg_b = avg_b / (kernel->size * kernel->size);
	blur->pixels[pixel_n].r = avg_r;
	blur->pixels[pixel_n].b = avg_b;
	
	/*printf("%d - %d\n]",img->pixels[pixel_n].g, avg_g);*/
	blur->pixels[pixel_n].g = avg_g;
}

