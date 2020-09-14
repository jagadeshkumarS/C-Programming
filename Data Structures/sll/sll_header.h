#ifndef __HEADER_H_
#define __HEADER_H_
#define red "\x1b[31m"
#define green "\x1b[32m"
#define reset "\x1b[0m"
#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int rollno;
	char name[25];
	float mark;
	struct student *next;
}ST;
void add_begin(ST **);
void add_middle(ST **);
void add_end(ST **);
void retrive_data(ST **);
void rev_print(ST *);
void rev_data(ST *);
void rev_link(ST **);
void print(ST *);
void save(ST *);
int count(ST *);
void delete(ST **,int);
void delete_all(ST **);
#endif