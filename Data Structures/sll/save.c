#include"header.h"
void _save_record(ST *ptr)
{
	FILE *fp;
	fp = fopen("student_record.txt","w");
	fprintf(fp,"--------------------------------------------\n");
	fprintf(fp,"| Roll no |          Name          | marks |\n");
	fprintf(fp,"--------------------------------------------\n");
	while(ptr!=NULL)
	{
		fprintf(fp,"| %-7d | %-22s | %-3.2f |\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
	fprintf(fp,"--------------------------------------------\n");
}




