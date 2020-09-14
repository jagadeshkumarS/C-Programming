#include"header.h"
void print_rev(ST *ptr)
{
/*	if(ptr)
	{
		print_rev(ptr->next);
		printf("| %-7d | %-22s | %-3.2f |\n",ptr->rollno,ptr->name,ptr->marks);
	}
*/
	ST **a;
	int i,c = count_record(ptr);
	a=malloc(sizeof(ST *)*c);
	for(i=0;ptr;ptr=ptr->next,i++)
		a[i]=ptr;
	for(--i;i>=0;i--)
		printf("| %-7d | %-22s | %-3.2f |\n",a[i]->rollno,a[i]->name,a[i]->marks);
}
