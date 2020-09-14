#include"header.h"
void rev_links(ST **ptr)
{
	ST *temp;

	while(*ptr)
	{
		temp=(*ptr)->prv;
		(*ptr)->prv = (*ptr)->next;
		(*ptr)->next = temp;

		*ptr=(*ptr)->prv;
	}
	*ptr = temp->prv;
}
