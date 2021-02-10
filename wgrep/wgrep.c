//Hey your code goes here..!
/* Project 1 of Advance OS 
Part 1b wgrep: creating a process similar to grep in UNIX */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  char *line_buffer = NULL;
  size_t line_buffer_size =0;
  ssize_t line_size = 0;
  FILE *fp;
  int file_counter = 2;
  char *target = argv[1];

  if (target == NULL) {
    printf("wgrep: searchterm [file ...]\n");
    exit(1);
  }
  // printf("%d", argc);

  if(argc == 2){
    fp = stdin;

     while (line_size >= 0) {
      line_size = getline(&line_buffer, &line_buffer_size, fp);
      if (strstr(line_buffer, target)){
        printf("%s", line_buffer);
      }
    }
    fclose(fp);
  }

  while (file_counter < argc) {
    if(argc > 2){
    // open the files in a while loopp to get them all
      // printf("%d", argc);
      fp = fopen(argv[file_counter], "r");

      // error handeling if you cannot open the file
      if (fp == NULL) {
        printf("wgrep: cannot open file\n");
        exit(1);
      }
    }


    // get the first line
    while (line_size >= 0) {
      line_size = getline(&line_buffer, &line_buffer_size, fp);
      if (strstr(line_buffer, target)){
        printf("%s", line_buffer);
      }
    }
    fclose(fp);
    file_counter ++;
  }
  exit(0);
}