#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
struct node
{
int data;
struct node *next;
};
struct node *startnode = NULL;
struct node *createlinkedList();
struct node *displayList(struct node *);
int main()
{
 int n;
printf("\n To create and display Singly Linked List :\n");
startnode = createlinkedList();
 displayList(startnode);
 return 0;
}
struct node *createlinkedList()
{
struct node *newnode, *ptr;
int num;
printf("\n Enter -1 to end");
printf("\n Enter the data :");
scanf("%d", &num);
while(num!=-1)
{
newnode = (struct node*)malloc(sizeof(struct node));
newnode -> data=num;
if(startnode==NULL)
{
newnode -> next = NULL;
startnode = newnode;
}
else
{
ptr=startnode;
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next = newnode;
newnode->next=NULL;
}
printf("\n Enter the data :");
scanf("%d", &num);
}
return startnode;
}
struct node *displayList(struct node *startnode)
{
printf("\n The Linked List is:\n");
struct node *ptr;
ptr = startnode;
while(ptr != NULL)
{
printf("\t %d", ptr -> data);
ptr = ptr -> next;
}
return startnode;
}
