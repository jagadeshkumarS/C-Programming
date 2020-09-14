#include"myheader.h"
void in_order(TREE *ptr,int n)
{
	if(ptr) {
		in_order(ptr->left,n);
		printf("%d->",ptr->data);
		in_order(ptr->right,n);
	}
}

