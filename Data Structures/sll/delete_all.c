#include"header.h"
void delete_all_std(ST **p)
{
	ST *t;
	while(*p)
	{
		t=*p;
		*p=(*p)->next;
		free(t);
	}
}
