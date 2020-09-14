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
void delet(TREE **,int);
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
	}
	else
		printf("no data present in tree\n");

	printf("enter roll to delet\n");
	scanf("%d",&n);
	delet(&hptr,n);
	printf("after delet\n");
	if(hptr)
	{
		printf("post order\n");
		post_order(hptr);
		printf("\npre order\n");
		pre_order(hptr);
		printf("\nin order\n");
		in_order(hptr);
		printf("\n");
	}
	else
		printf("no data present in tree\n");
	
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
TREE *parent;
TREE * search(TREE *ptr,int n)
{
	if(ptr==0)
		return 0;
	else if(n == (ptr)->roll)
		return ptr;
	else if(n < (ptr)->roll)
	{
		parent=ptr;
		return search((ptr)->left,n);
	}
	else
	{
		parent=ptr;
		return search((ptr)->right,n);
	}
}
void delet(TREE **ptr,int roll)
{
	TREE *p,*q,*r;
	parent=*ptr;
	q=search(*ptr,roll);
	p=parent;
if (q == *ptr)
	{

		printf ("Roots having the any one side NULL...\n");

		if ((*ptr)->left != NULL && (*ptr)->right == NULL)
		{
			r = q->left;
			while (r->right)
			{
				p = r;
				r = r->right;
			}
		}
		else
		{
			r = q->right;
			while (r->left)
			{
				p = r;
				r = r->left;
			}
		}

		q->roll = r->roll;
		q = r;
	}

	if (q->left != NULL && q->right != NULL)
	{
		printf ("q->left != NULL && q->right != NULL\n");

		r = q->left;
		p = q;
		while (r->right)
		{
			p = r;
			r = r->right;
		}
		q->roll = r->roll;
		q = r;
	}


	if (q->left == NULL && q->right != NULL)
	{
		printf ("q->left == NULL && q->right != NULL\n");

		if (q == p->left)
			p->left = q->right;
		else
			p->right = q->right;
		free(q);
		q = NULL;
		return;
	}

	if (q->left != NULL && q->right == NULL)
	{
		printf ("q->left != NULL && q->right == NULL\n");

		if (q == p->left)
			p->left = q->left;
		else
			p->right = q->left;
		free(q);
		q = NULL;
		return;
	}

	if (q->left == NULL && q->right == NULL)
	{
		printf ("q->left == NULL && q->right == NULL\n");

		if (q == p->left)
			p->left = NULL;
		else
			p->right = NULL;
		free(q);
		q = NULL;
		return;
	}
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
