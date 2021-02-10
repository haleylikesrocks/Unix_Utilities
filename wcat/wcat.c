//Hey your code goes here..!
/* Project 1 of Advance OS 
Part 1b wcat: creating a process similar to cat in UNIX */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define BUFSIZ 1024;

int main(int argc, char **argv)
{
  FILE *fp;
  int file_counter = 1;

  // varibles for handeling longer lines
  size_t size = 1024;
  char * buffer = malloc(size);

  // if no files are specified exit with code 0
  if (argc == 1){
    exit(0);
  }

  // loop to handel multiple files
  while (file_counter < argc) {
    fp = fopen(argv[file_counter], "r");

    // exit if file can't be opened
    if (fp == NULL) {
      printf("wcat: cannot open file\n");
      exit(1);
    }

    // loop to read from file
    while (!feof(fp)) {
      fgets(buffer, size, fp);
      printf("%s", buffer);
      buffer[0] = '\0';
    }

    // closing current file
    fclose(fp);
    file_counter ++;
    
  }

  //successful exit
  return(0);
}