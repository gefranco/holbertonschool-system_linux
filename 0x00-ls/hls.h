#ifndef HLS_H
#define HLS_H
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
int hls(int argc, char **argv);
int prtfnms(struct dirent *read, char);
int prtcntdir(char *name, int, char);
int mngargse(int, char**);
int mngargss(int, char**);
#endif
