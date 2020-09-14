#include<stdio.h>
#include<stdlib.h>
void selction_sort(int a[],int ele)
{
	int i,j,temp;
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
}
int main()
{
	int a[]={4,2,1,12,6,15,16},b[]={3,5,9,4,11,10},elea,eleb,elec,*p;
	int i,j,k;
	elea=sizeof(a)/sizeof(a[0]);
	eleb=sizeof(b)/sizeof(b[0]);
	elec=elea+eleb;
	p=malloc(sizeof(elec));

	selction_sort(a,elea);
	selction_sort(b,eleb);

	for(k=0,i=0,j=0;k<elec;k++)
	{
		if((a[i]>b[j]) && j<eleb)
		{
			p[k]=b[j];
			j++;
		}
		else if(i<elea)
		{
			p[k]=a[i];
			i++;
		}
	}
	for(i=0;i<elec;i++)
		printf("%d ",p[i]);
	printf("\n");
}	
