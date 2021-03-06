#include <stdio.h>
#define size 50

void insertelement(int[], int);
void deleteelement(int[]);
void display(int[]);

int front =  - 1;
int rear =  - 1;

int main()
{
    int n, choice;
    int queue[size];
  
    while (1)
    {
        printf("\nENTER YOUR CHOICE\n\n");
        
        printf("1.Insert an element to circular queue \n\n");

        printf("2.Delete an element from circular queue \n\n");

        printf("3.Display the elements of circular queue \n\n");

        printf("4.Exit \n\n");

        printf("Enter your choice : ");
		        
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                printf("\nEnter number: ");
                scanf("%d", &n);
                insertelement(queue, n);
                break;
            case 2:
                deleteelement(queue);
                break;
            case 3:
                display(queue);
                break;
        }
    }
}


void insertelement(int queue[], int item)
{
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        printf("queue is full");
        return;
    }
    else if (rear ==  - 1)
    {
        rear++;
        front++;
    }
    else if (rear == size - 1 && front > 0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = item;
}

void display(int queue[])
{
    int i;
    printf("\n");
    if (front > rear)
    {
        for (i = front; i < size; i++)
        {
            printf("%d ", queue[i]);
        }
        for (i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}

void deleteelement(int queue[])
{
    if (front ==  - 1)
    {
        printf("Queue is empty ");
    }
    else if (front == rear)
    {
        printf("\n %d deleted", queue[front]);
        front =  - 1;
        rear =  - 1;
    }
    else
    {
        printf("\n %d deleted", queue[front]);
        front++;
    }
}
