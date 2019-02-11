#include "interface.h"

int numInts = 100;
int minInt = 1;
int maxInt = 255;
bool customNum = false;

char* inputFile = "";
char* outputFile = "";
char* countFile = "";

bool useSeed = false;
unsigned long seed = 1;

int compar(const void *a, const void *b) {

   return ( *(int*)a - *(int*)b );

}

int main(int argc, char* argv[], char*envp[]) {

  argus(argc, argv, SORTER);

  struct timeval begin, end;

  gettimeofday(&begin, NULL);

  bool readFile = false;

  FILE *inputFileName;

  if(strcmp(inputFile, "") != 0) {

    inputFileName = fopen(inputFile, "r");

    if(inputFileName == NULL) {
      fprintf(stderr, "Input file cannot open");
      printstderr(SORTER);
    }
    readFile = true;
  }

  bool writeFile = false;
  FILE *outputFileName;

  if(strcmp(outputFile, "") != 0) {

    outputFileName = fopen(outputFile, "w");

    if(outputFileName == NULL) {
      fprintf(stderr, "Output file cannot open");
      printstderr(SORTER);
    }

    writeFile = true;

  }

  bool countToFile = false;
  FILE *countFileName;

  if(strcmp(countFile, "") != 0) {

    countFileName = fopen(countFile, "w");

    if(countFileName == NULL) {

      fprintf(stderr, "Count file cannot open");
      printstderr(SORTER);

    }
    countToFile = true;
  }

  int numToSort;

  if(readFile) {

    fscanf(inputFileName, "%d\n", &numToSort);
  }
  else {

    scanf("%d", &numToSort);
  }

  if(customNum && numToSort != numInts) {

    fprintf(stderr, "-n error: value passed must equal value in 1st line of input");
    printstderr(SORTER);

  }

  int* nums = (int*)malloc(numToSort * sizeof(int));

  if(nums == NULL) {

    fprintf(stderr, "Malloc error");
    exit(1);

  }

  for(int i = 0; i < numToSort; i++) {

    int temp;
    if(readFile) {

      fscanf(inputFileName, "%d\n", &temp);
    }

    else {

      scanf("%d", &temp);

    }
    if(temp < minInt) {

      fprintf(stderr, "Input value < min-int");
      printstderr(SORTER);

    }
    else if(temp > maxInt) {

      fprintf(stderr, "Input value > max-int");
      printstderr(SORTER);

    }

    nums[i] = temp;
  }

  qsort((void*)nums, numToSort, sizeof(int), compar);

  for(int i = 0; i < numToSort; i++) { 

    if(writeFile) {

      int res = fprintf(outputFileName, "%d\n", nums[i]);

      if(res < 0) {

	fprintf(stderr, "fprintf error");
	exit(1);

      }
    }
    else {

      int res = printf("%d\n", nums[i]);

      if(res < 0) {

	fprintf(stderr, "fprintf error");
	exit(1);

      }
    }   
  }

  char* userName = envp[9]+5;
  int ch = 0;
  while(userName[ch] != '\0') {

    int count = 0;

    for(int i = 0; i < numToSort; i++) {

      if(nums[i] == (int)userName[ch]) count++;

    }

    if(countToFile) {

      int res = fprintf(countFileName, "%c\t%d\t%d\n", userName[ch], (int)userName[ch], count);

      if(res < 0) {
	fprintf(stderr, "fprintf error");
	exit(1);

      }
    }
    else {

      int res = printf("%c\t%d\t%d\n", userName[ch], (int)userName[ch], count);

      if(res < 0) {
	fprintf(stderr, "fprintf error");
	exit(1);

      }
    }   
    ch++;
  }

  gettimeofday(&end, NULL);

  int microseconds = (end.tv_sec - begin.tv_sec) * 1000000 + ((int)end.tv_usec - (int)begin.tv_usec);

  int res = fprintf(stderr, "%d.%.6d\n", (microseconds / 1000000), (microseconds % 1000000));  

  if(res < 0) {

    fprintf(stderr, "Error when calling printf");
    exit(1);

  }
  
  if(readFile) {

    int res = fclose(inputFileName);

    if(res != 0) {
      fprintf(stderr, "Error! Cannot close input file");
      exit(1);

    }
  }

  if(writeFile) {

    int res = fclose(outputFileName);

    if(res != 0) {
      fprintf(stderr, "Error! Cannot close input file");
      exit(1);

    }
  }

  if(countToFile) {

    int res = fclose(countFileName);

    if(res != 0) {
      fprintf(stderr, "Error! Cannot close input file");
      exit(1);

    }
  }

  free(nums);
  
  return 0;
}
