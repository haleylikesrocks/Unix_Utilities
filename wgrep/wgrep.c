//Hey your code goes here..!
/* Project 1 of Advance OS 
Part 1b wgrep: creating a process similar to grep in UNIX */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  char buffer[500];
  FILE *fp;
  int file_counter = 2;
  char *target = argv[1];

  if (target == NULL) {
    printf("wgrep: searchterm [file ...]\n");
    exit(1);
  }

  do {
    if(argc > 2){
            // open the files in a while loopp to get them all
      fp = fopen(argv[file_counter], "r");


      if (fp == NULL) {
        printf("wgrep: cannot open file\n");
        exit(1);
      }
    }
    if (argc == 1) {
      // open the files in a while loopp to get them all
      while (fgets (buffer, 500, stdin)) {
      
        if (strstr(buffer, target)){
          printf("%s", buffer);
        }
      
      }
    }

    while (!feof(fp)) {
      if( fgets (buffer, 500, fp)!=NULL ) {
        if (strstr(buffer, target)){
          printf("%s", buffer);
        }
      }
    }
    fclose(fp);
    file_counter ++;
  } while (file_counter < argc);
  return (0);
}