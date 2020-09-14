#include"header.h"
void print(ST *p)
{
	ST *t;
	while(p)
	{
		printf("%-6d %-20s %-3.2f\n",p->rollno,p->name,p->marks);
		t=p;
		p=p->next;
	}
	/*
	printf("Reverse Data Printing...\n");
	p=t;
	while(p)
	{
		printf("%-6d %-20s %-3.2f\n",p->rollno,p->name,p->marks);
		p=p->prv;
	}*/
}
