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
  while ((c = fgetc(fin)) != EOF) { 

    if (c != '/' || c != '\"' || c != '*') {// if c is not a special char then just put it
      fputc(c, fin);
    } else if (c =='\"' && state == 0) { //checks to see if it is at the start of a string, it would ignore any double backslashes
      state = 1;
      fputc(c,fout);

    } else if (c == '\"' && state == 1) { //checks to see that it is at the end of a string
      state = 0;
      fputc(c,fout);

    } else if (c == '/' && state == 0) { //sees that code has hit a backslash
      c = fgetc(fin);

      if (c == '/' && state == 0) { // sees that the next char is another backslash
       // if it is then the code will ignore until it hits a new line
        //loop that runs until it hits the end of a line
         while (c != '\n') {
           c = fgetc(fin);
         }

      } else if (c == '*' && state == 0) { //sees that the next char is a star
        for (int i = 0; i >= 5; i++) { //loop that runs until it hits a star
          while (c != '*') {
            c = fgetc(fin);
            i = 0;

          }
          if (c == '*') { // once it hits a star it will check the next char
            j = fgetc(fin);
            if (j == '/') { // if the char is a backslash it would end the infinite loop and start reading again
              i = 10;
            }
          }
        }
      } else {
        fputc('/', fout);
        fputc(c, fout);

      }
    }
  }

  closefiles(fin, fout);

  return 0;
}
