#ifndef __MYHEADER_H_
#define __MYHEADER_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tree
{
	int data;
	struct tree *left,*right;
}TREE;
TREE *parent;
void add_node(TREE **,int);
void pre_order(TREE *,int);
void post_order(TREE *,int);
void in_order(TREE *,int);
TREE *search(TREE *,int);
void delete_node(TREE **,int);

#endif
