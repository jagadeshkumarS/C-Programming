#include"header.h"
void ret_file(ST **ptr)
{
	FILE *fp = fopen("student_record.data","r");
	if(fp==0)
	{
		printf("File not present\n");
		return;
	}
	ST rec,*temp,*last;
	rec.next=0;
	while(fscanf(fp,"%d %s %f",&rec.rollno,rec.name,&rec.marks)!=EOF)
	{
		temp=malloc(sizeof(ST));
		*temp = rec;
		if(*ptr==NULL)
			*ptr=temp;
		else
			last->next = temp;
		last = temp;
	}
}
