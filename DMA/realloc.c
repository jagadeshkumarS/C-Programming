#include<stdio.h>
#include<stdlib.h>
int main()
{
  //Allocate DMA
  int *p = (int *)malloc(5*sizeof(int));

  printf("Before Realloc - p : %p\n",p);
  printf("p[-1] : %d\n",p[-1]);

  p = (int *)realloc(p,10*sizeof(int));
  
  printf("After Realloc - p : %p\n",p);
  printf("p[-1] : %d\n",p[-1]);

  //De-Allocate the DMA
  free(p);

  //Allocate DMA
  int *a = (int *)malloc(5*sizeof(int));
  printf("Before Realloc - a : %p\n",a);

  int *b = (int *)malloc(5*sizeof(int));
  printf("Before Realloc - b : %p\n",b);

  a = (int *)realloc(p,10*sizeof(int));
  printf("After Realloc - a : %p\n",a);

  //De-Allocate the DMA
  free(a);
  free(b);

  return 0;
}
