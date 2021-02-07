//Hey your code goes here..!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  FILE *fp;
  int file_counter = 1;
  int letter_count = 1;
  char letter;
  //int total_count;

  do {
    fp = fopen(argv[file_counter], "r");
    // error handeling if can't open the file
    if(fp == NULL){
      printf("wunzip: file1 [file2..]\n");
      exit(1);
    }

    while(!feof(fp)){
      fread(&letter_count, 4, 1, fp);
      fread(&letter, 1, 1, fp);
      for(int i = 0; i < letter_count; i++){
        printf("%c", letter);
      }
      // printf("%d", letter_count);
      // printf("%c", letter);
    }

    fclose(fp);
    file_counter++;
  } while (file_counter < argc);

  exit(0);
}