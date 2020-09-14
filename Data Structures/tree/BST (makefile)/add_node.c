#include"myheader.h"
void add_node(TREE **ptr,int n)
{
	if(!*ptr)
	{
		TREE *temp=(TREE *)malloc(sizeof(TREE));
		temp->data=n;
		temp->left = temp->right = NULL;
		*ptr = temp;
		return;
	}
	else if (n < (*ptr)->data)
		return add_node(&(*ptr)->left,n);
	else
		return add_node(&(*ptr)->right,n);
}

