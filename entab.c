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

  int c, tabs;
  while ((c = fgetc(fin)) != EOF) {
    if (c == ' ') {
      tabs++;
      while (tabs >= TABTOSPACE) {
        fputc('\t', fout);
      }
    } else if (tabs > 0) {
      while (tabs > 0) {
        fputc(' ', fout);
        tabs--;
      }
      fputc(c,fout);
    } else {
      fputc(c, fout);
    }
  }

  closefiles(fin, fout);

  return 0;
}
