#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
	struct st *prv;
	int roll;
	struct st *next;
}ST;
void add_end(ST **ptr);
void print(ST *ptr);

int main()
{
	ST *hptr=0;
	char ch;
	do
	{
		add_end(&hptr);
		printf("do you want another node(y/n)\n");
		scanf(" %c",&ch);	
	}while((ch=='y') || (ch=='Y'));
	printf("normal print\n");
	print(hptr);
}
void add_end(ST **ptr)
{
	static ST *last;
	ST *temp=(ST *)malloc(sizeof(ST));
	printf("enter roll\n");
	scanf("%d",&temp->roll);
	if(*ptr==0)
	{	
		temp->prv=temp->next=temp;
		*ptr=temp;
		last=temp;
	}
	else
	{
		temp->prv=last;
		last->next=temp;
		temp->next=*ptr;
		temp->next->prv=temp;
		last=temp;
	}
}
void print(ST *ptr)
{
	ST *temp=ptr,*last;
	while(1)
	{
		printf("%d-->",ptr->roll);
		last=ptr;
		ptr=ptr->next;
		if(temp==ptr)
			break;
	}
	temp=last;
	printf("\nreverse printing\n");
	while(1)
	{
		printf("%d-->",temp->roll);
		temp=temp->prv;
		if(temp==last)
			break;
	}
	printf("\n");
}
