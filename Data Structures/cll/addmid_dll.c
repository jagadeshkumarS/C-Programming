#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	struct student *prv;
	int roll;
	struct student *next;
}ST;
void add_mid(ST **ptr);
void print(ST *ptr);
main()
{
	ST *hptr=0;
	char ch;
	do
	{
		add_mid(&hptr);
		printf("do you want another node(y/n)\n");
		scanf(" %c",&ch);
	}while((ch=='y')||(ch=='Y'));
	print(hptr);
}
void add_mid(ST **ptr)
{
	ST *temp=(ST *)malloc(sizeof(ST));
	printf("enter roll\n");
	scanf("%d",&temp->roll);
	static ST *last;
	if((*ptr==0)||(temp->roll < (*ptr)->roll))
	{
		if(*ptr==0)
		{
			temp->next=temp->prv=temp;
			*ptr=temp;
			last=temp;
		}
		else
		{	last=*ptr;
			while(last->next!=(*ptr))
				last=last->next;
			temp->next=*ptr;
			temp->prv=last;
			(*ptr)->prv=temp;
			last->next=temp;
			*ptr=temp;	
		}
	}
	else
	{
		if(temp->roll < last->roll)
		{
			ST *last1=*ptr;
			while(temp->roll > last1->next->roll)
				last1=last1->next;
			temp->next=last1->next;
			temp->prv=last1;
			last1->next=temp;
			temp->next->prv=temp;
		}
		else
		{
			temp->next=*ptr;;
			temp->prv=last;
			last->next=temp;
			(*ptr)->prv=temp;
			last=temp;
		}
		
	}
}
void print(ST *ptr)
{
	ST *temp=ptr,*last;;
	while(1)
	{
		printf("%d-->",ptr->roll);
		last=ptr;
		ptr=ptr->next;
		if(temp==ptr)
			break;
	}
	printf("\n reverse printing\n");
	temp=last;
	
	while(1)
	{
		printf("%d-->",temp->roll);
		temp=temp->prv;
		if(temp==last)
			break;
	}
printf("\n");
}

