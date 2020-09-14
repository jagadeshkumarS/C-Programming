#include"header.h"
int count_record(ST *ptr)
{
	int c=0;
	while(ptr!=NULL)
	{
		c++;
		ptr=ptr->next;
	}
	return c;
}



