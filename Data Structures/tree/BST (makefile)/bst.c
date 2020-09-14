#include<stdio.h>
#include<stdlib.h>
typedef struct BST
{
	struct BST *left;
	int roll;
	struct BST *right;
}TREE;

void add_tree(TREE **ptr,int n);
void in_order(TREE *ptr);
void pre_order(TREE *ptr);
void post_order(TREE *ptr);
TREE * search(TREE *,int);
main()
{
	TREE *hptr=0,*p;
	int num,n;
	char ch;
	do
	{
		printf("enter the num\n");
		scanf("%d",&num);
		add_tree(&hptr,num);
		printf("do you want another node\n");
		scanf(" %c",&ch);
	}while((ch=='y')||(ch=='Y'));
	if(hptr)
	{
		printf("post order\n");
		post_order(hptr);
		printf("\npre order\n");
		pre_order(hptr);
		printf("\nin order\n");
		in_order(hptr);
		printf("\n");
	//	return;
	}
	else
	{
		printf("no data present in tree");
	//	return;
	}
	printf("enter roll\n");
	scanf("%d",&n);
	p=search(hptr,n);
	if(p)
		printf("%d is present at %p location\n",n,p);
	else
		printf("data not present\n");
	
}
void add_tree(TREE **ptr,int n)
{
	if(*ptr==0)
	{
		*ptr=(TREE *)malloc(sizeof(TREE));
		(*ptr)->left=0;
		(*ptr)->right=0;
		(*ptr)->roll=n;
		return;
	}
	else if(n< (*ptr)->roll)
		add_tree(&(*ptr)->left,n);
	else
		add_tree(&(*ptr)->right,n);
}
TREE * search(TREE *ptr,int n)
{
	if(ptr==0)
		return 0;
	else if(n == (ptr)->roll)
		return ptr;
	else if(n < (ptr)->roll)
		return search((ptr)->left,n);
	else
		return search((ptr)->right,n);
}
void post_order(TREE *ptr)
{
	if(ptr)
	{
		post_order(ptr->left);
		post_order(ptr->right);
		printf("%d-->",ptr->roll);
	}
}
void pre_order(TREE *ptr)
{
	if(ptr)
	{
		printf("%d-->",ptr->roll);
		pre_order(ptr->left);
		pre_order(ptr->right);
	}
}
void in_order(TREE *ptr)
{
	if(ptr)
	{
		in_order(ptr->left);
		printf("%d-->",ptr->roll);
		in_order(ptr->right);
	}
}
