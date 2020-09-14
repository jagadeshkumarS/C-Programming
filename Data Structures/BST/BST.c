#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tree
{
        struct tree *left;
        int roll;
        struct tree *right;
}TREE;

TREE *parent;

TREE * search(TREE *ptr,int roll)
{
	if (ptr == NULL)
		return 0;

	else if (ptr->roll == roll)
		return ptr;

	else if (roll < ptr->roll)
	{
		parent = ptr;
		return search (ptr->left,roll);
	}

	else
	{
		parent = ptr;
		return search (ptr->right,roll);
	}
}

void delete (TREE **ptr,int roll)
{
	TREE *p,*q,*r;
	parent = *ptr;
	q = search (*ptr,roll);
	p = parent;

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

void pre_order(TREE *ptr)
{
	if (ptr)
	{
                printf ("%d -- ",ptr->roll);
                pre_order(ptr->left);
                pre_order(ptr->right);
        }
}

void post_order(TREE *ptr)
{
        if (ptr)
        {
                post_order(ptr->left);
                post_order(ptr->right);
                printf ("%d -- ",ptr->roll);
        }
}

void in_order(TREE *ptr)
{

        if (ptr)
        {
                in_order(ptr->left);
                printf ("%d -- ",ptr->roll);
                in_order(ptr->right);
        }
}

void add_tree(TREE **ptr,int num)
{
        if (*ptr == NULL)
        {
                *ptr = (TREE *)malloc(sizeof(TREE));
                (*ptr)->left = NULL;
		(*ptr)->right = NULL;
                (*ptr)->roll = num;
		return;
        }
        else if (num < (*ptr)->roll)
                add_tree(&(*ptr)->left,num);
        else
                add_tree(&(*ptr)->right,num);
}

int main ()
{
	TREE *ret,*hptr = 0;
	char ch;
	int roll;
	do
	{
		printf ("Enter the roll no...\n");
		scanf ("%d",&roll);
		add_tree(&hptr,roll);
		printf ("Would you like to and another node...\n");
		scanf (" %c",&ch);
	}while (ch == 'y' || ch == 'Y');

	if (hptr)
	{
		printf ("Post Order...\n");
		post_order(hptr);

		printf ("\nPre Order...\n");
		pre_order(hptr);

		printf ("\nIn Order...\n");
		in_order(hptr);
		printf ("\n");
	}

	else
	{
		printf ("No data of the link...\n");
		return;
	}

	printf ("Do you want to search a no (y/n)...\n");
	scanf (" %c",&ch);
	if (ch == 'y' || ch == 'Y')
	{
		printf ("Enter the roll no...\n");
		scanf ("%d",&roll);
		ret = (TREE *) search(hptr,roll);
		if (ret == 0)
			printf ("No not found...\n");
		else
			printf ("%d no is found at %u\n",ret->roll,(unsigned)ret);
	}

	printf ("Do you want to delete a no (y/n)...\n");
	scanf (" %c",&ch);
	if (ch == 'y' || ch == 'Y')
	{
		printf ("Enter the roll...\n");
		scanf ("%d",&roll);
		delete (&hptr,roll);

		printf ("Post Order...\n");
		post_order(hptr);

		printf ("\nPre Order...\n");
		pre_order(hptr);

		printf ("\nIn Order...\n");
		in_order(hptr);
		printf ("\n");
	}

}
