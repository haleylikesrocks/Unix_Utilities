//Hey your code goes here..!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  FILE *fp;
  int file_counter = 1;
  // char letter;
  // int letter_count = 0;
  // int total_count = 1;
  char *line_buffer = NULL;
  size_t line_buffer_size =0;
  ssize_t line_size = 0;
  // char buffer[500];
  
  do {
    fp = fopen(argv[file_counter], "r");
    if(fp == NULL){
      printf("wzip: file1 [file2..]\n");
      exit(1);
    }


    // fgets(buffer, 500, fp);

    line_size = getline(&line_buffer, &line_buffer_size, fp);
    printf("%s", line_buffer);

    // need to close file here
    file_counter++;
  } while (file_counter < argc);
  exit(0);
}