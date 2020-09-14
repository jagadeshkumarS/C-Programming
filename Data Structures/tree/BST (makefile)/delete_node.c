#include"myheader.h"
void delete_node(TREE **ptr,int n)
{
	TREE *p,*q,*r;
	parent = *ptr;
	q = search(*ptr,n);
	p = parent;
	if(q == *ptr) {
		if ((*ptr)->left != NULL && (*ptr)->right == NULL) {
			r = q->left;
			while (r->right) {
				p = r;
				r = r->right;
			}
		}
		else {
			r = q->right;
			while (r->left) {
				p = r;
				r = r->left;
			}
		}
		q->data = r->data;
		q = r;
	}
	if (q->left != NULL && q->right != NULL) {
		printf ("q->left != NULL && q->right != NULL\n");
		r = q->left;					                
		p = q;
		while (r->right) {
			p = r;
			r = r->right;
		}
		q->data = r->data;
		q = r;
	}
	if (q->left == NULL && q->right != NULL) {
		printf ("q->left == NULL && q->right != NULL\n");
		if (q == p->left)
			p->left = q->right;
		else
			p->right = q->right;
		free(q);		
		q = NULL;
		return;
	}
	if (q->left != NULL && q->right == NULL) {
		printf ("q->left != NULL && q->right == NULL\n");
		if (q == p->left)
			p->left = q->left;
		else
			p->right = q->left;
		free(q);
		q = NULL;
		return;
	}
	if (q->left == NULL && q->right == NULL) {
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



