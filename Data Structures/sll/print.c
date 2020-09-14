#include"header.h"
void print(ST *p)
{
	printf("--------------------------------------------\n");
	printf("| Roll no |          Name          | marks |\n");
	printf("--------------------------------------------\n");
	while(p!=NULL)
	{
		printf("| %-7d | %-22s | %-3.2f |\n",p->rollno,p->name,p->marks);
		p=p->next;
	}
	printf("--------------------------------------------\n");
}

