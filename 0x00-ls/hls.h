#ifndef HLS_H
#define HLS_H
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
int hls(int argc, char **argv);
int prtfnms(struct dirent *read);
int ldir(char *dir_name);
#endif
