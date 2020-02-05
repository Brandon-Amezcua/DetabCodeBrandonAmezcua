#include <stdio.h>
#include <stdbool.h>
#include "fileread.h"

#define TABTOSPACE 10

int main (int argc, const char* argv[]) {
  FILE* fin;
  FILE* fout;
  int n;
  printf("Test 1\n");
  bool ok = openfiles(argc, argv, &fin, &fout, &n);
  if (!ok) {exit(1);}
printf("Test 2\n");
  int c;
  while ((c = fgetc(fin)) != EOF) {

    if (c == ' ') {
      int count = 1;
      while ((c = fgetc(fin)) != EOF && (c = fgetc(fin)) == ' ') {
        ++count;
      }
      int ntabs = count / n;
      int nspaces = count % 2;
      while (ntabs-- > 0) {
        fputc('\t', fout);
      }
      while (nspaces-- > 0) {
        fputc(' ', fout);
      }
    } else {
      fputc(c, fout);
    }

    /*if (c != ' ' && c != '\t') {
      fputc(c, fout);
    } else if (c == ' ') {
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
    }*/
  }

  closefiles(fin, fout);

  return 0;
}
