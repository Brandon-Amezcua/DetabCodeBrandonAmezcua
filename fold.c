#include <stdio.h>
#include <stdbool.h>
#include "fileread.h"

#define MAXLINE 30

int main (int argc, const char* argv[]) {
  FILE* fin;
  FILE* fout;
  int n;

  bool ok = openfiles(argc, argv, &fin, &fout, &n);
  if (!ok) {exit(1);}

  int c;
  int numchar = 0;
  while ((c = fgetc(fin)) != EOF) {
    numchar++;
    if (c == '\n') {
      numchar = 0;
    }
    // if the program encounters a tab it will iterate through the for loop
    // adding spaces till it hits the tabstop
    if (numchar >= MAXLINE) {
      if (c == ' ') {
        fputc('\n', fout);
        numchar = 0;
      } else {
        fputc(c, fout);
      }
    } else {
      fputc(c, fout);
    }

  }

  closefiles(fin, fout);

  return 0;
}
