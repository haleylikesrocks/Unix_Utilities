//Hey your code goes here..!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  FILE *fp;
  int file_counter = 1;
  char letter;
  int letter_count = 1;
  int total_count = 0;
  char *line_buffer = NULL;
  size_t line_buffer_size =0;
  ssize_t line_size = 0;
  
  do {
    fp = fopen(argv[file_counter], "r");
    // error handeling if can't open the file
    if(fp == NULL){
      printf("wzip: file1 [file2..]\n");
      exit(1);
    }

    // get line from file
    line_size = getline(&line_buffer, &line_buffer_size, fp);

    // loop through text and compress
    letter = line_buffer[total_count];
    while(total_count < line_size){
      total_count++;
      if(letter == line_buffer[total_count]){
        letter_count++;
      }
      else {
        printf("%d", letter_count);
        printf("%c", letter);
        letter = line_buffer[total_count];
        letter_count = 1;
      }
    }
    total_count = 0;
    fclose(fp);
    file_counter++;
  } while (file_counter < argc);
  exit(0);
}