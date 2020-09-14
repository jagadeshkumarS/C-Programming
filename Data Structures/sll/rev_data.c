#include"header.h"
void rev_data(ST *ptr)
{
	ST *p1,*p2,temp;
	int i,j,c;
	
	c=count_record(ptr);

	p1=ptr;
	
	for(i=0;i<c/2;i++)
	{
		p2=ptr;
		for(j=0;j<c-i-1;j++)
			p2=p2->next;

		temp=*p1;
		*p1=*p2;
		*p2=temp;

		temp.next=p1->next;
		p1->next=p2->next;
		p2->next=temp.next;

		p1=p1->next;
	}
}
