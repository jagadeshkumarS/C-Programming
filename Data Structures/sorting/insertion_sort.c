#include<stdio.h>
int main()
{
	int a[]={4,6,3,1,5,2};
	int ele,i,j,key;
	ele=sizeof(a)/sizeof(a[0]);

	printf("Before...\n");
	for(i=0;i<ele;i++)
		printf("%d ",a[i]);
	printf("\n");

	for(i=1;i<ele;i++)
	{
		key=a[i];
		for(j=i-1;(a[j]>key)&&(j>=0);j--)
			a[j+1]=a[j];
		a[j+1]=key;
	}
	
	printf("After...\n");
	for(i=0;i<ele;i++)
		printf("%d ",a[i]);
	printf("\n");	
}
