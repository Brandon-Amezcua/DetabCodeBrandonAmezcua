#include <stdio.h>
#include <stdbool.h>
#include "fileread.h"

int main (int argc, const char* argv[]) {
  FILE* fin;
  FILE* fout;
  int n;

  bool ok = openfiles(argc, argv, &fin, &fout, &n);
  if (!ok) {exit(1);}

  int c;
  int numparen = 0;
  int numbrac = 0;
  int numcurl = 0;
  int dquote = 0;
  int squote = 0;
  while ((c = fgetc(fin)) != EOF) {
    if (c == '(') {
      numparen++;
    } else if (c == ')') {
      numparen--;
    } else if (c == '[') {
      numbrac++;
    } else if (c == ']') {
      numbrac--;
    } else if (c == '{') {
      numcurl++;
    } else if (c == '}') {
      numcurl--;
    } else if (c == '\'') {
      squote++;
    } else if (c == '\"') {
      dquote++;
    } else {

    }
    fputc(c, fout);
  }

  if (numparen == 0 && numbrac == 0 && numcurl == 0 &&  dquote % 2 == 0 && squote % 2 == 0) {
    fputs("\nNo syntax errors", fout);
  } else {
    fputs("\nSome syntax errors", fout);
  }

  closefiles(fin, fout);

  return 0;
}
