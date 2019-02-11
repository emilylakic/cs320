#include "interface.h"

int numInts = 100;
bool customNum = false;
int maxInt = 255;
int minInt = 1;
bool useSeed = false;
unsigned long seed = 1;
char* countFile = "";
char* inputFile = "";
char* outputFile = "";

int main(int argc, char* argv[]) {
  argus(argc, argv, GENERATOR);

  if(useSeed) { 
	srand(seed);
} else {
srand(time(NULL)); //separate these
}
  bool writeFile = false;
  FILE *fp;
  if(strcmp(outputFile, "") != 0) {
    fp = fopen(outputFile, "w");
    if(fp == NULL) {
      fprintf(stderr, "Error! Output file cannot open.");
      printstderr(GENERATOR);
    }
    writeFile = true;
  }
  
  if(writeFile) {
    int res = fprintf(fp, "%d\n", numInts);

    if(res < 0) {
      fprintf(stderr, "Error with calling fprintf!");
      exit(1);
    }
  }
  else {
    int res = printf("%d\n", numInts);

    if(res < 0) {
      fprintf(stderr, "Error with calling fprintf!");
      exit(1);
    }
  }

  for(int i = 0; i < numInts - 1; i++) {
    int random = (rand() % (maxInt - minInt)) + minInt;
    if(writeFile) {
      int res = fprintf(fp, "%d\n", random);
      if(res < 0) {
	fprintf(stderr, "Error with calling fprintf!");
	exit(1);
      }
    }
    else {
      int res = printf("%d\n", random);
      if(res < 0) {
	fprintf(stderr, "Error with calling fprintf!");
	exit(1);
      }
    } 
  }

  if(writeFile) {
    int res = fclose(fp);
    if(res != 0) {
      fprintf(stderr, "Error! Cannot close output file.");
      exit(1);
    }
  }
  
  return 0;
}
