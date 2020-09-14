#include<stdio.h>
void quicksort(int arr[],int low,int high);
int partition(int a[],int low,int high);
int main()
{
	int arr[10]={43,37,11,98,36,72,65,10,88,78},i,high;
	high=sizeof arr/sizeof arr[0]-1;
	//printf("Enter the elements\n");
	
	quicksort(arr,0,high);

	for(i=0;i<high;i++)
	printf("%d\t",arr[i]);

	printf("\n");
}
void quicksort(int arr[],int low,int high)
{
	int j;

	if(low<high)
	{
		j=partition(arr,low,high);
		quicksort(arr,low,j-1);
		quicksort(arr,j+1,high);
	}
}
int partition(int a[],int low,int high)
{
	int i=low+1,j=high,pivot,temp;
	pivot = a[low];

	while(1)
	{
		while((i<high)&&(pivot>=a[i]))
		i++;

		while((pivot<a[j]))
		j--;

		if(i<j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		else
		{
		//	temp = a[low];
			a[low]=a[j];
			a[j] = pivot;
			return j;
		}
	}
}
/* Quick sort(Partition Exchange Sort):-
   -----------------------------------
	In this technique, a problem is divided into small problems which are again divided into smaller problems and so on.
	This technique is used where there is large amount of data is to be sorted.
	Quick sort is a very fast and very efficient sorting technique because of less exchanges are needed to 
	place it  at its proper position in the list.
	
   pivot means: on which, something operation is going on.
*/