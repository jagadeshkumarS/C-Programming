#include"header.h"
void add_middle(ST **ptr)
{
	ST *temp;
	temp=malloc(sizeof(ST));
	printf("Name :");
	scanf(" %[^\n]s",temp->name);
	printf("Roll No. :");
	scanf("%d",&temp->rollno);
	printf("Marks :");
	scanf("%f",&temp->marks);
	if((*ptr==NULL)||(temp->rollno < (*ptr)->rollno))
	{
		temp->next=*ptr;
		*ptr=temp;
	}
	else
	{
		ST *last=*ptr;
		while((last->next!=NULL)&&(last->next->rollno < temp->rollno))
			last=last->next;
		temp->next=last->next;
		last->next=temp;
	}
}
