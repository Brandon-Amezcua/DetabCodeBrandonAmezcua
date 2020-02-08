#include <stdio.h>
#include <stdbool.h>
#include "fileread.h"

#define TABTOSPACE 10

int main (int argc, const char* argv[]) {
  FILE* fin;
  FILE* fout;
  int n;

  bool ok = openfiles(argc, argv, &fin, &fout, &n);
  if (!ok) {exit(1);}

  int c;
  while ((c = fgetc(fin)) != EOF) {

    if (c != ' ') {
      fputc(c,fout);
    } else {
      int count = 1;
      while ((c = fgetc(fin)) != EOF && (c = fgetc(fin)) == ' ') {
        ++count;
      }

      int ntabs = count / TABTOSPACE;
      int nspaces = count % TABTOSPACE;

      while (ntabs-- > 0) {
        fputc('\t', fout);
      }
      while (nspaces-- > 0) {
        fputc(' ', fout);
      }
    }

  }

  closefiles(fin, fout);

  return 0;
}
