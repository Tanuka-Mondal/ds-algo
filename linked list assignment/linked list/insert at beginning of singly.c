#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;           
    struct node *next;  
}*startnode;


void createList(int n);
void insertNodeAtBeginning(int data);
void displayList();


int main()
{
    int n, data;

   
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();


    printf("\nEnter data to insert at beginning of the list: ");
    scanf("%d", &data);
    insertNodeAtBeginning(data);

    printf("\nData in the list \n");
    displayList();

    return 0;
}



void createList(int n)
{
    struct node *newNode, *ptr;
    int data, i;

    startnode = (struct node *)malloc(sizeof(struct node));

    if(startnode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        startnode->data = data;
        startnode->next = NULL; 

        ptr = startnode;

        
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; 
                newNode->next = NULL;

                ptr->next = newNode; 
                
                ptr = ptr->next; 
           }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}



void insertNodeAtBeginning(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->next = startnode; 

        startnode = newNode;          
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

void displayList()
{
    struct node *ptr;

   
    if(startnode == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        ptr = startnode;
        while(ptr != NULL)
        {
            printf("Data = %d\n", ptr->data); 
            ptr = ptr->next;              
        }
    }
}				    	
