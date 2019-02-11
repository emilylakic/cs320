#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <stdbool.h>
#include <string.h>
#define GENERATOR 0
#define SORTER 1

extern bool customNum;
extern int numInts;
extern int minInt;
extern int maxInt;
extern bool useSeed;
extern unsigned long seed;
extern char* inputFile;
extern char* outputFile;
extern char* countFile;
char* get_userName();
void printstderr(int);
void argus(int, char**, int);

#endif
