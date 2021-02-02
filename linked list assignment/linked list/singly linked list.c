#include <stdio.h>
#include <stdlib.h>


struct node {
    int data, val;           
    struct node *next;  
}*startnode;


void createList(int n);
void insertNodeAtBeginning(int data);
void insertNodeAtEnd(int data);
void insertAfterNode(int afterVal, int data);
void deleteFirstNode();
void deleteLastNode();
void displayList();

int main()
{
    int n, data, choice=1;
    int afterVal;
   
    
    
    while(choice != 0)
    {
        
        printf("============================================\n");
        printf("SINGLY LINKED LIST PROGRAM\n");
        printf("============================================\n");
        printf("1. Create List\n");
        printf("2. Insert node - at beginning\n");
        printf("3. Insert node - at end\n");
        printf("4. Delete first node\n");
        printf("5. Delete last node\n");
        printf("6. Display list\n");
        printf("7. Insert after given node\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);
        
         switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);

                createList(n);
                break;
            case 2:
                printf("Enter data of first node : ");
                scanf("%d", &data);

                insertNodeAtBeginning(data);
                break;
            case 3:
                printf("Enter data of last node : ");
                scanf("%d", &data);

                insertNodeAtEnd(data);
                break;
            case 4:
                
                deleteFirstNode();

                break;
            case 5:
			
			    deleteLastNode();
			    break;
            case 6:
                displayList();
                break;
            case 7:
			    printf("Enter the data after which node you want to add a node : ");
				scanf("%d", &afterVal);
				printf("Enter the data you want to insert:");
				scanf("%d", &data);
				
				//insertAfterNode(afterVal, data);
				displayList();
	
				break;    
            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-5");
        }

        printf("\n\n\n\n\n");
    }

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


void insertNodeAtEnd(int data)
{
    struct node *newNode, *ptr;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->next = NULL; 

        ptr = startnode;

       
        while(ptr != NULL && ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = newNode; 

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

void insertAfterNode(int afterVal, int data)
{
    struct node *ptr=startnode, *tmp;
    
    if(ptr == NULL)
    return;

    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->val = data;
    tmp->next = NULL;

    while(ptr->val != afterVal)
        ptr = ptr->next;
    tmp->next = ptr->next;
    ptr->next = tmp;
    
    printf("Data Inserted\n");
}


void deleteFirstNode()
{
    struct node *toDelete;

    if(startnode == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = startnode;
        startnode = startnode->next;

        printf("\nData deleted = %d\n", toDelete->data);

        
        free(toDelete);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}

void deleteLastNode()
{
    struct node *toDelete, *secondLastNode;

    if(startnode == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = startnode;
        secondLastNode = startnode;

        
        while(toDelete->next != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }

        if(toDelete == startnode)
        {
            startnode = NULL;
        }
        else
        {
           
            secondLastNode->next = NULL;
        }

       
        free(toDelete);

        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
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
