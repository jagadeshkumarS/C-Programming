#include<stdio.h>
int Q[5],front = 0,rear = 0;
void enqueue(int data);
void dequeue();
void display();

int main()
{
	int num,op;

	while(1) {
	printf("Enter the option\n");
	printf("1) enqueue 2) dequeue 3) display 4) exit\n");
	scanf("%d",&op);

	switch(op)
	{
		case 1: if(rear < 5) {
			printf("Enter the number to insert\n");
			scanf("%d",&num);
			enqueue(num);
			}
			else
			printf("Queue Overfloaw...\n");
			break;
		case 2: if((front >= 0) && (front < rear)) 
			dequeue();
			else
			printf("Queue Underflow...\n");
			break;
		case 3: display();
			break;
		case 4: printf("Exited...\n");
			return;
		default : printf("Invalid option...\n");
	}

	}
}
void enqueue(int data)
{
	printf("%d data item inserted in Queue...\n",data);
	Q[rear++] = data;	
}
void dequeue()
{
	printf("%d data item deleted from Queue...\n",Q[front]);
	Q[front++] = 0;
}
void display()
{
	if(rear == 0) {
	printf("Queue is empty...\n");
	return;
	}
	int i;
	for(i = 0; i < rear ; i++)
	printf("%d\t",Q[i]);
	printf("\n");
}



