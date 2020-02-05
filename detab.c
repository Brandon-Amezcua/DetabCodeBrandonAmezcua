#include <stdio.h>
#include <stdbool.h>
#include "fileread.h"

#define MAXTAB 10

int main (int argc, const char* argv[]) {
  FILE* fin;
  FILE* fout;
  int n;

  // printf("This is test 1\n");

  bool ok = openfiles(argc, argv, &fin, &fout, &n);
  if (!ok) {exit(1);}

  // printf("This is test 2\n");

  int c;
  int numtab = 0;
  while ((c = fgetc(fin)) != EOF) {
    numtab++;
    if (c == '\n') {
      numtab = 0;
    }
    // if the program encounters a tab it will iterate through the for loop
    // adding spaces till it hits the tabstop
    if (c == '\t') {
      while (numtab <= MAXTAB) {
        fputc(' ', fout);
        numtab++;
      }
      numtab = 0;
    }
      fputc(c, fout);
    //once the program has iterated 10 times, the numtab will be reset
    if (numtab == MAXTAB) {
      numtab = 0;
    }
    // printf("This is test 3\n");
    // printf("%c\n", c);
  }

  // printf("This is test 4\n");

  closefiles(fin, fout);

  // printf("This is test 5\n");

  return 0;
}
