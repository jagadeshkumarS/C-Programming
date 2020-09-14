#include"header.h"
void add_end(ST **p)
{
	ST *t=malloc(sizeof(ST));
	t->rollno = count(*p)+1;
	printf("Enter the following information\n");
	printf("Name :");
	scanf(" %[^\n]s",t->name);
	printf("Marks :");
	scanf("%f",&t->marks);
	t->prv=NULL;
	t->next=NULL;
	if(!*p)
		*p=t;
	else
	{
		ST *last=*p;
		while(last->next)
			last=last->next;
		last->next=t;
		t->prv=last;
	}
}
