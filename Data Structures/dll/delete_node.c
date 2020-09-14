#include"header.h"
void delete_node(ST **ptr)
{
	ST *prv,*temp=*ptr;
	int rollno;
	printf("Enter the rollno :");
	scanf("%d",&rollno);

	while(temp)
	{
		if(temp->rollno == rollno)
		{
			if(*ptr == temp)	
			{
				*ptr=temp->next;
				if(*ptr!=NULL)
					(*ptr)->prv=NULL;
				free(temp); temp=NULL;
				return;
			}
			else
			{
				temp->prv->next = temp->next;
				if(temp->next)
					temp->next->prv = temp->prv;
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
	printf("%d Data is not present to delete\n",rollno);
}
