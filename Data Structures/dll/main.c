#include"header.h"
void main()
{
	ST *hptr=NULL;
	char ch;
	do
	{
		add_middle(&hptr);
		//add_end(&hptr);
		//add_begin(&hptr);
		printf("Do you want add another node (y/n):");
		scanf(" %c",&ch);
	}while(ch=='y'||ch=='Y');
	print(hptr);
	delete_node(&hptr);
	print(hptr);
}
