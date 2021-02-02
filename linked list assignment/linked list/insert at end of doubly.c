#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node * preptr;
    struct node * ptrnext;
}*startnode, *endnode;
 

void Listcreation(int n);
void insertNodeAtEnd(int num);
void displayList(int a);

int main()
{
    int n,num1,a;
    startnode = NULL;
    endnode = NULL;
	printf("\n\n Doubly Linked List : Insert new node at the end in a doubly linked list :\n");
	printf("------------------------------------------------------------------------------\n");	   	
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    Listcreation(n); 
    a=1;
    displayList(a);
    printf(" Input data for the last node : ");
    scanf("%d", &num1);
    insertNodeAtEnd(num1);
    a=2;
    displayList(a);
    return 0;
}
 
void Listcreation(int n)
{
    int i, num;
    struct node *ftNode;
 
    if(n >= 1)
    {
        startnode = (struct node *)malloc(sizeof(struct node));
 
        if(startnode != NULL)
        {
            printf(" Input data for node 1 : "); 
            scanf("%d", &num);
 
            startnode->num = num;
            startnode->preptr = NULL;
            startnode->ptrnext = NULL;
            endnode = startnode;
            for(i=2; i<=n; i++)
            {
                ftNode = (struct node *)malloc(sizeof(struct node));
                if(ftNode != NULL)
                {
                    printf(" Input data for node %d : ", i);
                    scanf("%d", &num);
                    ftNode->num = num;
                    ftNode->preptr = endnode;    
                    ftNode->ptrnext = NULL;
                    endnode->ptrnext = ftNode;   
                    endnode = ftNode;            
                }
                else
                {
                    printf(" Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf(" Memory can not be allocated.");
        }
    }
}

void insertNodeAtEnd(int num)
{
    struct node * newnode;
 
    if(endnode == NULL)
    {
        printf(" No data found in the list!\n");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->num = num;
        newnode->ptrnext = NULL;        
        newnode->preptr = endnode;       
        endnode->ptrnext = newnode;      
        endnode = newnode;                 
    }
}

void displayList(int m)
{
    struct node * ptr;
    int n = 1;
    if(startnode == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        ptr = startnode;
        if (m==1)
        {
        printf("\n Data entered in the list are :\n");
        }
        else
        {
         printf("\n After insertion the new list are :\n");   
        }
        while(ptr != NULL)
        {
            printf(" node %d : %d\n", n, ptr->num);
            n++;
            ptr = ptr->ptrnext; 
        }
    }
}
