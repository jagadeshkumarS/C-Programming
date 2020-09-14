#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
	struct st *prv;
	int roll;
	struct st *next;
}ST;
void add_begin(ST **ptr);
void print(ST *ptr);

int main()
{
	ST *hptr=0;
	char ch;
	do
	{
		add_begin(&hptr);
		printf("do you want another node(y/n)\n");
		scanf(" %c",&ch);	
	}while((ch=='y') || (ch=='Y'));
	printf("normal print\n");
	print(hptr);
}
void add_begin(ST **ptr)
{
	ST *temp=(ST *)malloc(sizeof(ST));
	printf("enter roll\n");
	scanf("%d",&temp->roll);
	static ST *last;
	if(*ptr==0)
	{
		temp->prv=*ptr;
		temp->next=temp;
		*ptr=temp;
		last=temp;
	}
	else
	{
		temp->next=*ptr;
		*ptr=temp;
		last->next=temp;
		temp->prv=last;
		temp->next->prv=temp;
	}
}
void print(ST *ptr)
{
	ST *temp,*last=ptr;
	while(1)
	{
		printf("%d-->",ptr->roll);
		temp=ptr;
		ptr=ptr->next;
		if(last==ptr)
			break;
	}
	last=temp;
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
