//Hey your code goes here..!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  FILE *fp;
  int file_counter = 2;

  if (argc == 1){
    printf("wzip: file1 [file2..]\n");
    exit(1);
  }
  
  while (argc >= file_counter){
    fp = fopen(argv[file_counter], "r");

    
    file_counter++;
  }
  exit(0);
}