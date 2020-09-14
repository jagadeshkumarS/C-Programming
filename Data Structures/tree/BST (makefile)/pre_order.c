#include"myheader.h"
void pre_order(TREE *ptr,int n)
{
	if(ptr) {
		printf("%d->",ptr->data);
		pre_order(ptr->left,n);
		pre_order(ptr->right,n);
	}
}

