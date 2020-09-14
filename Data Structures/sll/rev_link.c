#include"header.h"
//Using Loops
void rev_link(ST **ptr)
{
	ST *q=0,*r;
	while(*ptr)
	{
		r=q;
		q=*ptr;
		*ptr=(*ptr)->next;
		q->next=r;
	}
	*ptr=q;
}

//Using Ary_of_ptr
/*void rev_link(ST **ptr)
{

	ST **a;
	int i,c;
	c=count(*ptr);
	
	a=malloc(c*sizeof(ST *));
	
	for(i=0;*ptr;*ptr=(*ptr)->next,i++)
		a[i]=*ptr;
	
	a[0]->next=NULL;
	for(i=1;i<c;i++)
		a[i]->next=a[i-1];

	*ptr=a[i-1];
}*/

//Using Recursion
/*void rev_link(ST **ptr)
{
	ST *f,*r;
	if(*ptr == NULL)
		return;
	f = *ptr;
	r = f->next;

	if(r == NULL)
		return;
	rev_link(&r);
	f->next->next = f;
	f->next = NULL;
	*ptr = r;
}
*/