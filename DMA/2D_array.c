#include<stdio.h>
#include<stdlib.h>
int main()
{
  int r,c,i,j;

  //Get number of rows and columns
  printf("Enter the row and column value : ");
  scanf("%d%d",&r,&c);

  //Allocate DMA
  int **p = (int **)malloc(r*sizeof(int *));
  for(i=0;i<r;i++)
    p[i] = (int *)malloc(c*sizeof(int));

  //Get and Display the Elements
  printf("Enter the elements\n");
  for(i=0;i<r;i++)
  for(j=0;j<c;j++)
    scanf("%d",&p[i][j]);
  printf("Elements : \n");
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
      printf("%d\t",p[i][j]);
    printf("\n");
  }

  //De-Allocate the DMA
  for(i=0;i<r;i++)
    free(p[i]);
  free(p);

  return 0;
}
