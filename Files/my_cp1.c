#include<stdio.h>
int main(int argc,char *argv[])
{
  if(argc <= 2)
  {
    printf("Usage : %s <src> <dest> ... \n",argv[0]);
    return 0;
  }

  FILE *fp = fopen(argv[1],"r");
  if(fp == NULL)
  {
    printf("File doesn't Exist\n");
    return 0;
  }

  int i;
  char ch,op;
  FILE *fd;
  for(i=2;i<argc;i++)
  {
    fd = fopen(argv[i],"r");
    if(fd != NULL)
    {
      printf("Do you wamt to overwrite %s (y/n) : ",argv[i]);
      scanf(" %c",&op);
    }
    if((op == 'y')||(fd == NULL))
    {
	fd = fopen(argv[i],"w");
    	while((ch=fgetc(fp))!=EOF)
	  fputc(ch,fd);
    }
    rewind(fp);
    fclose(fd);
  }
}
