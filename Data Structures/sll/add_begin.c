#include"header.h"
void add_begin(ST **ptr)
{
	ST *temp;
	temp=malloc(sizeof(ST));
	printf("Name :");
	scanf(" %[^\n]s",temp->name);
	printf("Roll No. :");
	scanf("%d",&temp->rollno);
	printf("Marks :");
	scanf("%f",&temp->marks);
	
	temp->next=*ptr;
	*ptr=temp;
}

