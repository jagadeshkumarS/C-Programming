#include<stdio.h>
int main()
{
	int a[]={4,10,5,3,8,9};
	int ele,i,j,temp;
	ele=sizeof(a)/sizeof(a[0]);

	printf("Before...\n");
	for(i=0;i<ele;i++)
		printf("%d ",a[i]);
	printf("\n");

	for(i=0;i<ele-1;i++)
	{
		for(j=i+1;j<ele;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	
	printf("After...\n");
	for(i=0;i<ele;i++)
		printf("%d ",a[i]);
	printf("\n");	
}
