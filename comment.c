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
  int j;
  int state = 0;
  int star = 0;
  while ((c = fgetc(fin)) != EOF) {

    if (c != '/' && c != '\"' && c != '*') {// if c is not a special char then just put it
      fputc(c, fout);
    }

    if (c =='\"' && state == 0) { //checks to see if it is at the start of a string, it would ignore any double backslashes
      state = 1;
      fputc(c,fout);

    } else if (c == '\"' && state == 1) { //checks to see that it is at the end of a string
      state = 0;
      fputc(c,fout);

    }

    if (c == '/' && state == 0) { //sees that code has hit a backslash
      c = fgetc(fin);

      if (c == '/' && state == 0) { // sees that the next char is another backslash
       // if it is then the code will ignore until it hits a new line
        //loop that runs until it hits the end of a line
         while (c != '\n') {
           c = fgetc(fin);
         }

      } else if (c == '*' && state == 0) { //sees that the next char is a star
        while ((c == fgetc(fin)) != '*' && (c == fgetc(fin)) != EOF) {}

      } else {
        fputc(c,fout);
        printf("%d",c);
      }
    }
  }

  closefiles(fin, fout);

  return 0;
}
