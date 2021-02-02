#include<stdio.h>
#include<process.h>
#define MAX 10
 
typedef struct dequeue
{
	int data[MAX];
	int rear,front;
}dequeue;
 
void initialize(dequeue *p);
int empty(dequeue *p);
int full(dequeue *p);
void addRear(dequeue *p,int x);
void addFront(dequeue *p,int x);
int deleteFront(dequeue *p);
int deleteRear(dequeue *p);
void print(dequeue *p);
 
void main()
{
	int i,x,op,n;
	dequeue q;
	
	initialize(&q);
	
	do
	{
		printf("\n1.Create a dequeue");
		printf("2.Insert at rear");
		printf("3.Insert at front");
		printf("4.Delete from rear");
		printf("5.Delete from front");
		printf("6.Print the dequeue");
		printf("7.Exit\n");
		printf("\nENTER YOUR CHOICE:\n");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1: printf("\nEnter number of elements:");
					scanf("%d",&n);
					initialize(&q);
					printf("\nEnter the data:");
					
					for(i=0;i<n;i++)
					{
						scanf("%d",&x);
						if(full(&q))
						{
							printf("\nQueue is full!!");
							exit(0);
						}
						addRear(&q,x);
					}
					break;
					
			case 2: printf("\nEnter element to be inserted:");
					scanf("%d",&x);
							
					if(full(&q))
					{
						printf("\nQueue is full!!");
						exit(0);
					}
					
					addRear(&q,x);
					break;
							
			case 3: printf("\nEnter the element to be inserted:");
					scanf("%d",&x);
							
					if(full(&q))
					{
						printf("\nQueue is full!!");
						exit(0);
					}
					
					addFront(&q,x);
					break;
							
			case 4: if(empty(&q))
					{
						printf("\nQueue is empty!!");
						exit(0);
					}
							
					x=deleteRear(&q);
					printf("\nElement has to delete  %d\n",x);
					break;
					
			case 5: if(empty(&q))
					{
						printf("\nQueue is empty!!");
						exit(0);
					}
							
					x=deleteFront(&q);
					printf("\nElement has to delete %d\n",x);
					break;
							
			case 6: print(&q);
					break;
					
			default: break;
		}
	}while(op!=7);
}
 
void initialize(dequeue *P)
{
	P->rear=-1;
	P->front=-1;
}
 
int empty(dequeue *P)
{
	if(P->rear==-1)
		return(1);
	
	return(0);
}
 
int full(dequeue *P)
{
	if((P->rear+1)%MAX==P->front)
		return(1);
	
	return(0);
}
 
void addRear(dequeue *P,int x)
{
	if(empty(P))
	{
		P->rear=0;
		P->front=0;
		P->data[0]=x;
	}
	else
	{
		P->rear=(P->rear+1)%MAX;
		P->data[P->rear]=x;
	}
}
 
void addFront(dequeue *P,int x)
{
	if(empty(P))
	{
		P->rear=0;
		P->front=0;
		P->data[0]=x;
	}
	else
	{
		P->front=(P->front-1+MAX)%MAX;
		P->data[P->front]=x;
	}
}
 
int deleteFront(dequeue *P)
{
	int x;
	
	x=P->data[P->front];
	
	if(P->rear==P->front)
		initialize(P);
	else
		P->front=(P->front+1)%MAX;
	
	return(x);
}
 
int deleteRear(dequeue *P)
{
	int x;
	
	x=P->data[P->rear];
	
	if(P->rear==P->front)
		initialize(P);
	else
		P->rear=(P->rear-1+MAX)%MAX;
		
	return(x);
}
 
void print(dequeue *P)
{
	if(empty(P))
	{
		printf("\nQueue is empty!!");
		exit(0);
	}
	
	int i;
	i=P->front;
	
	while(i!=P->rear)
	{
		printf("\n%d",P->data[i]);
		i=(i+1)%MAX;
	}
	
	printf("\n%d\n",P->data[P->rear]);
}
