#include"header.h"
void delete_std(ST **p)
{
	int rollno;
	ST *prv,*temp=*p;
	printf("Enter the student roll No. :");
	scanf("%d",&rollno);
	while(temp)
	{
		if(temp->rollno == rollno) 
		{
			if(*p == temp) 
			{
				*p = (*p)->next;
				free(temp); temp=NULL;
				return;
			}
			else 
			{
				prv->next=temp->next;
				free(temp); temp=NULL;
				return;
			}
		}
		else
		{
			prv=temp;
			temp=temp->next;
		}
	}
	printf(red"%d Roll No Data is not present\n"reset,rollno);
}
