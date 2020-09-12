#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"file_driver.c"
int main(int argc, char *argv[])
{
  if(argc != 4)
  {
    printf("Usage : %s <file> <find_word> <replace_word>\n",argv[0]);
    return 0;
  }
  FILE *fp = fopen(argv[1],"r");
  if(fp == NULL)
  {
    perror("File ");
    return 0;
  }
  int c = Noof_Char(fp),i=0,j;
  char *buf = (char *)malloc(c*sizeof(char));
  char ch,*stop;
  rewind(fp);
  while((ch=fgetc(fp))!=EOF)
    buf[i++] = ch;buf[i] = '\0';

  fclose(fp);
  
  fp = fopen(argv[1],"w");
  for(i=0;stop = strstr(buf+i,argv[2]);i = i+strlen(argv[2]))
  {
    for(j=stop-buf;i<j;i++)
	    fputc(buf[i],fp);
    fputs(argv[3],fp);
  }
  for(;buf[i];i++)
	  fputc(buf[i],fp);

  fclose(fp);
  return 0;
}
