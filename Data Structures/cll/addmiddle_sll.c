#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
	int roll;
	struct st *next;
}ST;
void add_middle(ST **);
void print(ST *);
main()
{
	ST *hptr=0;
	char ch;
	do
	{
		add_middle(&hptr);
		printf("do you want anothe node(y/n)\n");
		scanf(" %c",&ch);
	}while((ch=='y') || (ch=='Y'));

	printf("circular link list is\n");
	print(hptr);
}
void add_middle(ST **ptr)
{
	ST *temp=(ST *)malloc(sizeof(ST));
	printf("enter roll\n");
	scanf("%d",&temp->roll);
	static ST *last;

	if((*ptr==0) || (temp->roll < (*ptr)->roll))
	
	{
	
		if(*ptr==0)
		{	
			temp->next=temp;
			*ptr=temp;
		}
		else
		{
			last=*ptr;
			while(last->next!=(*ptr))
				last=last->next;
			temp->next=*ptr;
			*ptr=temp;
			last->next=*ptr;
		}
		
	}
	else
	{
		if(temp->roll < last->roll)
		{
			ST *last1=*ptr;
			while(temp->roll > last1->next->roll)
				last1=last->next;
			
			temp->next=last1->next;
			last1->next=temp;
		}
		else
		{
			temp->next=*ptr;
			last->next=temp;
		}
		last=temp;
	}
}
void print(ST *ptr)
{
	ST *temp=ptr;
	while(1)
	{
		printf("%d-->",ptr->roll);
		ptr=ptr->next;
		if(temp==ptr)
			break;
	}
	printf("\n");
}
