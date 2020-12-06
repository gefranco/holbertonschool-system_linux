#ifndef HLS_H
#define HLS_H
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
int hls(int argc, char **argv);
int prtfnms(struct dirent *read, char);
int prtcntdir(char *name, int, char, int, int);
int mngargse(int, char**);
int mngargss(int, char**);
int mrprms(int i, int argc, char *argv[]);
int _strcmp(char*, char*);
int _strlen(char *s);
int tofiargs(int argc, char *argv[]);
#endif
