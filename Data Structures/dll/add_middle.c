#include"header.h"
void add_middle(ST **p)
{
	ST *t=malloc(sizeof(ST));
	printf("Enter the following information\n");
	printf("Roll No.:");
	scanf("%d",&t->rollno);
	printf("Name :");
	scanf(" %[^\n]s",t->name);
	printf("Marks :");
	scanf("%f",&t->marks);
	t->prv=NULL;
	t->next=NULL;
	if(!*p || (t->rollno < (*p)->rollno))
	{
		t->next=*p;
		*p=t;
	}
	else
	{
		ST *last=*p;
		while((last->next)&&(last->next->rollno < t->rollno))
			last=last->next;
		t->prv=last;
		last->next=t;
	}
}
