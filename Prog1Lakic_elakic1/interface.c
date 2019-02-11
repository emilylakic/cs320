#include "interface.h"

void printstderr(int prgm) {
  if(prgm == GENERATOR) {
    fprintf(stderr, "prog1generator [-u] [-n <num-integers>] [-m <min-int>] [-M <max-int>] [-s <seed>] [-o <output-file-name>]");
    exit(1);
  }
  else {
    fprintf(stderr, "prog1sorter [-u] [-n <num-integers>] [-m <min-int>] [-M <max-int>] [-i <input-file-name>] [-o <output-file-name>] [-c <count-file-name>]");
    exit(1);
  }
}

void argus(int argc, char* args[], int prgm) {
  for(int i = 1; i < argc; i++) {
    if(strcmp(args[i], "-u") == 0) {
      printstderr(prgm);
    }
  }
  int curr = 1;
  while(curr < argc) {
    if(args[curr][0] != '-') {
      printstderr(prgm);
    }
    else { 
      switch(args[curr][1]) {

      case 'u':
	printstderr(prgm);
	break;
	
      case 'n':
	if(argc <= curr+1) {
	  printstderr(prgm);
	}
	int input_n = 0;
	input_n = (int)strtol(args[curr+1],NULL, 10);

	if(input_n == 0) {
	  fprintf(stderr, "Integer conversion of -n input failed.");
	  printstderr(prgm);
	}
	else if(input_n < 1 || input_n > 1000000) {
	  printstderr(prgm);
	}
	else numInts = input_n;
	curr++;
	break;

      case 'm':
	if(argc <= curr+1) {
	  printstderr(prgm);
	}
	int input_m = 0;
	input_m = (int)strtol(args[curr+1],NULL, 10);

	if(input_m == 0) {
	  fprintf(stderr, "Integer conversion of -m input failed.");
	  printstderr(prgm);
	}
	else if(input_m < 1) {
	  printstderr(prgm);
	}
	else minInt = input_m;
	curr++;
	break;

      case 'M':
	if(argc <= curr+1) {
	  printstderr(prgm);
	}
	int input_M = 0;
	input_M = (int)strtol(args[curr+1],NULL, 10);

	if(input_M == 0) {
	  fprintf(stderr, "Integer conversion of -M input failed.");
	  printstderr(prgm);
	}
	else if(input_M < 1 || input_M > 1000000) {
	  printstderr(prgm);
	}
	else maxInt = input_M;
	curr++;
	break;

      case 's':
	if(prgm==SORTER || argc <= curr+1) {
	  printstderr(prgm);
	}
	int input_s = 0;
	input_s = (unsigned long)strtol(args[curr+1],NULL, 10);

	if(input_s == 0) {
	  int temp = 0;
	  while(args[curr+1][temp] != '\0') {
	    if(args[curr+1][temp] != '0') {
	      fprintf(stderr, "Integer conversion of -s input failed.");
	      printstderr(prgm);
	    }
	    temp++;
	  }
	}
	seed = input_s;
	useSeed = true;
	curr++;
	break;

      case 'i':
	if(prgm==GENERATOR || argc <= curr+1) {
	  printstderr(prgm);
	}
	else inputFile = args[curr+1];
	curr++;
	break;

      case 'o':
	if(argc <= curr+1) {
	  printstderr(prgm);
	}
	else outputFile = args[curr+1];
	curr++;
	break;

      case 'c':
	if(prgm==GENERATOR || argc <= curr+1) {
	  printstderr(prgm);
	}
	else countFile = args[curr+1];
	curr++;
	break;

      default:
	printstderr(prgm);
      }
    }
    curr++;
  }
  if(minInt > maxInt) {
    fprintf(stderr, "max-int cannot be less than min-int");
    printstderr(prgm);
  }
}
