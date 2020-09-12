#include<stdio.h>
int main(int argc,char *argv[])
{
  if(argc <= 1)
  {
    printf("Usage : %s <file1> ... \n",argv[0]);
    return 0;
  }
  int i;
  for(i=1;i<argc;i++)
    if(remove(argv[i]))
    {
      perror("remove ");
      printf("%s\n",argv[i]);
    }
  return 0;
}
