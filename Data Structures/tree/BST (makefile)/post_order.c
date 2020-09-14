#include"myheader.h"
void post_order(TREE *ptr,int n)
{
	if(ptr) {
		post_order(ptr->left,n);
		post_order(ptr->right,n);
		printf("%d->",ptr->data);
	}
}

