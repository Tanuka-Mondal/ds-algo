#include <stdio.h>

#define MAX 5

 
void insertelement();

void deleteelement();

void display();

int queueArray[MAX];

int rear = - 1;

int front = - 1;

int main()

{

    int choice;

    while (1)

    {
        printf("\nENTER YOUR CHOICE\n\n");
        
        printf("1.Insert an element to queue \n\n");

        printf("2.Delete an element from queue \n\n");

        printf("3.Display the elements of queue \n\n");

        printf("4.Exit \n\n");

        printf("Enter your choice : ");

        scanf("%d", &choice);

        switch (choice)

        {

            case 1:

            insertelement();

            break;

            case 2:

            deleteelement();

            break;

            case 3:

            display();

            break;

            case 4:

            exit(1);

            default:

            printf("Choice is not available \n");

        } 

    } 

} 

 

void insertelement()

{

    int add_item;

    if (rear == MAX - 1)

    printf("Queue Overflow \n");

    else

    {

        if (front == - 1)

        

        front = 0;

        printf("Insert the element in queue : ");

        scanf("%d", &add_item);

        rear = rear + 1;

        queueArray[rear] = add_item;

    }

} 

 

void deleteelement()

{

    if (front == - 1 || front > rear)

    {

        printf("Queue Underflow \n");

        return ;

    }

    else

    {

        printf("Element deleted from queue is : %d\n", queueArray[front]);

        front = front + 1;

    }

} 

 

void display()

{

    int i;

    if (front == - 1)

        printf("\nQueue is empty \n");
        
    else if (front == - 1 || front > rear)

    {

        printf("\nQueue Underflow \n");

        return ;

    }       

    else

    {

        printf("\nQueue is : \n\n");

        for (i = front; i <= rear; i++)

            printf("%d ", queueArray[i]);

        printf("\n");

    }

}
