//Hey your code goes here..!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  FILE *fp;
  int file_counter = 1;
  char letter;
  int letter_count = 0;
  int total_count = 0;
  char *line_buffer = NULL;
  size_t line_buffer_size =0;
  ssize_t line_size = 0;

  if(argc == 1){
    printf("wzip: file1 [file2 ...]\n");
    exit(1);
  }
  
  while (file_counter < argc) {
    fp = fopen(argv[file_counter], "r");
    
    // error handeling if can't open the file
    if(fp == NULL){
      printf("wzip: file1 [file2 ...]\n");
      exit(1);
    }
    
    // get line from file -try changing to fgets
    line_size = getline(&line_buffer, &line_buffer_size, fp);
    /// read the next file

    // loop through text and compress
    letter = line_buffer[total_count];

    while(total_count < line_size){
      total_count++;
      letter_count++;
      

      if(line_size == total_count){
        line_size = getline(&line_buffer, &line_buffer_size, fp);
        total_count = 0;
        if(line_size == -1){
          break;
        }
      }

      if(letter != line_buffer[total_count]) {
        // fwrite(&letter_count, 4, 1, stdout);
        // fwrite(&letter, 1, 1, stdout);
        printf("%d", letter_count);
        printf("%c", letter);

        letter = line_buffer[total_count];
        letter_count = 1;
      }
    }
    // total_count = 0;
    fclose(fp);
    file_counter++;
  }
  // fwrite(&letter_count, 4, 1, stdout);
  // fwrite(&letter, 1, 1, stdout);
  printf("%d", letter_count);
  printf("%c", letter);
  exit(0);
}