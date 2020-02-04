#include <stdio.h>
#include <stdbool.h>
#include "fileread.h"

int main (int argc, const char* argv[]) {
  FILE* fin;
  FILE* fout;
  int n;
  bool ok = openfiles(argc, argv, &fin, &fout, &n);

  closefiles(fin, fout);
  return 0;
}
