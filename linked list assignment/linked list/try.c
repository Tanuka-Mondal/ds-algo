#include <stdio.h>
#include <stdlib.h>


struct node {
    int data, val;           
    struct node *next;  
}*startnode;

void createList(int n);
void insertAfterNode(int afterVal, int data);
void displayList();

int main()
{
    int n, data, choice=1;
    int afterVal;
    
    printf("Enter the total number of nodes in list: ");
    scanf("%d", &n);

    createList(n);
                
    printf("\nData in the list \n");
    displayList();          
	
	printf("Enter the data after which node you want to add a node : ");
	scanf("%d", &afterVal);
	printf("Enter the data you want to insert:");
	scanf("%d", &data);
				
    insertAfterNode(afterVal, data);
    
    
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

void insertAfterNode(int afterVal, int data)
{
    struct node *ptr=startnode, *newNode, *preptr;
    
    if(ptr == NULL)
    return;

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = data;
    //newNode->next = NULL;
    preptr = ptr;

    while(ptr->val != afterVal)
    {
	    preptr = ptr;
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    preptr->next = newNode;
    //ptr->next = newNode;
    
    //return startnode;
    printf("Data Inserted\n");
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
