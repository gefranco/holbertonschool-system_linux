#include "multithreading.h"
#include <pthread.h>
#define NUM_THREADS 2
void *blur_img_thread(void *arg);
void blur_image(img_t *img_blur, img_t const *img, kernel_t const *kernel)
{
	blur_portion_t portion, portion2;
    
        pthread_t tid[NUM_THREADS];
    portion.img = img;
    portion.img_blur = img_blur;
    portion.kernel = kernel;
    portion.w = img->w;
    portion.h = img->h / 2;
    portion.x = 0;
    portion.y = 0;

    portion2.img = img;
    portion2.img_blur = img_blur;
    portion2.kernel = kernel;
    portion2.w = img->w;
    portion2.h = img->h / 2;
    portion2.x = 0;
    portion2.y = img->h / 2;

        pthread_create(&tid[0], NULL, blur_img_thread, (void *)&portion);
        pthread_create(&tid[1], NULL, blur_img_thread, (void *)&portion2);

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
        /*pthread_exit(NULL);*/

}

void *blur_img_thread(void *arg)
{
        blur_portion_t *portion = (blur_portion_t *)arg;
	
    	blur_portion(portion);	
	pthread_exit(NULL);
}

