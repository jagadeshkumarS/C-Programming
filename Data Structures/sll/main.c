#include"header.h"
int main()
{
	ST *hptr=0;
	char ch;
	int op,n;
	do
	{
		add:
		printf("In which method you want to add node\n");
		printf("1.add_begin();\n");
		printf("2.add_middle();\n");
		printf("3.add_end();\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1 : add_begin(&hptr); break;
			case 2 : add_middle(&hptr); break;
			case 3 : add_end(&hptr); break;
			default : printf("Invalid Option\n"); goto add;
		}
		printf("Do you want to add another node(y/n) :");
		scanf(" %c",&ch);
	}while(ch=='y'||ch=='Y');
	
	end:
	printf("Enter your Choice\n");
	printf("1.Add Node\n");
	printf("2.Reverse Print\n");
	printf("3.Reverse Data\n");
	printf("4.Reverse Link\n");
	printf("5.Delete Node\n");
	printf("6.Delete All Nodes\n");
	printf("7.Print Nodes\n");
	printf("8.Save Nodes\n");
	printf("9.Count Nodes\n");
	printf("10.Exit\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1 : goto add; break;
		case 2 : goto rev_print(hptr); break;
		case 3 : goto rev_data(hptr); break;
		case 4 : goto rev_link(&hptr); break;
		case 5 : printf("Nodes :\n");
		         print(hptr);
				 printf("Enter a roll no to delete : ");
				 scanf("%d",&n);
				 delete(&hptr,n);
				 printf("After Delete :\n");
				 print(hptr);
				 break;
		case 6 : printf("Deleting All nodes\n");
		         delete_all(&hptr);
				 printf("All Nodes are Deleted\n");
				 break;
		case 7 : print(hptr); break;
		case 8 : save(hptr); break;
		case 9 : count(hptr); break;
		case 10 : printf("Thank You\n"); return 0;
		default : printf("Invalid Option\n"); goto end;
	}
	printf("Do you want to Do it again : ");
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y')
		goto end;
	return 0;
}