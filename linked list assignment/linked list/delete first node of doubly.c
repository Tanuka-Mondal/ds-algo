#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node * preptr;
    struct node * ptrnext;
}*startnode, *endnode;
 

void Listcreation(int n);
void DeleteFirstNode();
void displayList(int a);

int main()
{
    int n,num1,a,insPlc;
    startnode = NULL;
    endnode = NULL;
	printf("\n\n Doubly Linked List : Delete node from the beginning of a doubly linked list :\n");
	printf("----------------------------------------------------------------------------------\n");	   	
    printf(" Input the number of nodes (3 or more ): ");
    scanf("%d", &n);
    Listcreation(n); 
    a=1;
    displayList(a);
    DeleteFirstNode();
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
                    ftNode->preptr = ennode;    
                    ftNode->ptrnext = NULL;     
                    endnode->ptrnext = fnNode;   
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

void DlListDeleteFirstNode()
{
    struct node * NodeToDel;
    if(stnode == NULL)
    {
        printf(" Delete is not possible. No data in the list.\n");
    }
    else
    {
        NodeToDel = stnode;
        stnode = stnode->nextptr;   
        stnode->preptr = NULL;      
        free(NodeToDel);            
    }
}

void displayDlList(int m)
{
    struct node * tmp;
    int n = 1;
    if(stnode == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        tmp = stnode;
        if (m==1)
        {
        printf("\n Data entered in the list are :\n");
        }
        else
        {
         printf("\n After deletion the new list are :\n");   
        }
        while(tmp != NULL)
        {
            printf(" node %d : %d\n", n, tmp->num);
            n++;
            tmp = tmp->nextptr; 
        }
    }
}
