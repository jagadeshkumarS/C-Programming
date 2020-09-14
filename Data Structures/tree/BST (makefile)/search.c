#include"myheader.h"
TREE *search(TREE *ptr,int data)
{
	if(!ptr)
		return NULL;
	else if(data == ptr->data) {
		parent = ptr;
		return ptr;
	}
	else if(data < ptr->data) {
		parent = ptr;
		return search(ptr->left,data);
	}
	else {
		parent = ptr;	
		return search(ptr->right,data);
	}
}
