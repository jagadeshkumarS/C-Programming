#include<stdio.h>
#include<stdlib.h>
#include"file_driver.c"
int main(int argc,char *argv[])
{
  if(argc!=2)
  {
    printf("Usage : %s <file>\n",argv[0]);
    return 0;
  }
  FILE *fp = fopen(argv[1],"r");
  if(fp == NULL)
  {
    perror("file ");
    return 0;
  }
  int c = Noof_Char(fp);
  int l = Noof_Line(fp);
  char *buf = (char *)malloc(25*sizeof(char));
  int w = 0;
  rewind(fp);
  while(fscanf(fp,"%s",buf)!=EOF)
    w++;
  printf(" %d %d %d %s \n",l,w,c-1,argv[1]);
  return 0;
}
