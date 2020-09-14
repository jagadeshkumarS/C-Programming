#include"header.h"
void add_end(ST **ptr)
{
	ST *temp;
	temp=malloc(sizeof(ST));
	printf("Name :");
	scanf(" %[^\n]s",temp->name);
	printf("Roll No. :");
	scanf("%d",&temp->rollno);
	printf("Marks :");
	scanf("%f",&temp->marks);
	if(*ptr==NULL)
	{
		temp->next=*ptr;
		*ptr=temp;
	}
	else
	{
		ST *last=*ptr;
		while(last->next!=NULL)
			last=last->next;
	
		temp->next=last->next;
		last->next=temp;
	}
}



