#include"header.h"
void add_begin(ST **p)
{
	ST *t=malloc(sizeof(ST));
	t->rollno = count(*p)+1;
	printf("Enter the following information\n");
	printf("Name :");
	scanf(" %[^\n]s",t->name);
	printf("Marks :");
	scanf("%f",&t->marks);
	t->next=*p;
	t->prv =NULL;
	if(*p)
		(*p)->prv=t;
	*p=t;
}
