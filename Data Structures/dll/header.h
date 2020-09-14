#ifndef __HEADER_H_
#define __HEADER_H_

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 256

typedef struct student
{
	int rollno;
	char name[32];
	float marks;
	struct student *prv,*next;
}ST;

void add_begin(ST **);
void add_middle(ST **);
void add_end(ST **);
int count(ST *);
void print(ST *);
void rev_links(ST **);
void delete_node(ST **);

#endif
