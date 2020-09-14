#include"myheader.h"
void main()
{
	TREE *hptr = NULL,*p;
	int data;
	char ch;
	do
	{
		printf("Enter the data :");
		scanf("%d",&data);
		add_node(&hptr,data);
		printf("Do you want to add another node(y/n) :");
		scanf(" %c",&ch);
	}while(ch=='Y'||ch=='y');

	printf("\nPre-Order\n");
	pre_order(hptr,data);
	printf("\nIn-Order\n");
	in_order(hptr,data);
	printf("\nPost-Order\n");
	post_order(hptr,data);

	printf("Enter the data which you want to delete :");
	scanf("%d",&data);
	delete_node(&hptr,data);
	
	printf("\nPre-Order\n");
	pre_order(hptr,data);
	printf("\nIn-Order\n");
	in_order(hptr,data);
	printf("\nPost-Order\n");
	post_order(hptr,data);
}



