#include "multithreading.h"
#include <stdio.h>
/**
 * blur_portion - blurs a portion of an image using a Gaussian Blur
 * @portion: points to a data structure
 */
void blur_portion(blur_portion_t const *portion)
{
	size_t avg;

	size_t init = (portion->y * portion->img->w) + portion->x;
	size_t end = init + (portion->w * portion->h);
	size_t x = portion->x;
	/*size_t exe_x = portion->img->w - (portion->x + portion->w);*/

	size_t rest = portion->img->w - (portion->x + portion->w);

	for (; init < end; init += 1, x += 1)
	{
		avg = (portion->img_blur->pixels[init].r +
		portion->img_blur->pixels[init].g +
		portion->img_blur->pixels[init].b) / 3;
		/*printf("%lu\n", avg);*/
		/*portion->img_blur->pixels[init].r = avg;*/
		portion->img_blur->pixels[init].g = avg;
		portion->img_blur->pixels[init].b = avg;
		if (x == portion->w)
		{
			init += rest;
			x = portion->x;
		}
	}
}


/*void gaussian_blur(void)*/

