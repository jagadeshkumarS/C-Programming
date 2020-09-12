#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"file_driver.c"
void Merge_Files(FILE *fp1,FILE *fp2,FILE *fd);
int main(int argc, char *argv[])
{
  if(argc != 4)
  {
    printf("Usage : %s <i/p_file1> <i/p_file2> <o/p_file>\n",argv[0]);
    return 0;
  }
  FILE *fp1 = fopen(argv[1],"r");
  FILE *fp2 = fopen(argv[2],"r");
  if((fp1 == NULL)||(fp2 == NULL))
  {
    perror("File ");
    return 0;
  }
  FILE *fd = fopen(argv[3],"w");
  Append_Files(fp1,fp2,fd);
  fclose(fp1);
  fclose(fp2);
  fclose(fd);
  return 0;
}
