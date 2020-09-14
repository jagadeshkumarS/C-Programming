#include"header.h"
int count(ST *p)
{
	int c;
	for(c=0;p;p=p->next,c++);
	return c;
}
