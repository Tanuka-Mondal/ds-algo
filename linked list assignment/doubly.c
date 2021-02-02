#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
struct node *next;
int data;
struct node *prev;
};
struct node *start = NULL;
struct node *createLinkedlist();
struct node *display(struct node *);
struct node *insertAtBeginning();
struct node *insertAtEnd();
struct node *insertBefore();
struct node *insertAfter();
struct node *deleteAtBeginning();
struct node *deleteAtEnd();
struct node *deleteBefore();
struct node *deleteAfter();
struct node *deleteNode();
int main()
{
int option;
do
{
printf("\n\n ENTER YOUR CHOICE");
printf("\n 1: Create a doubly linked list");
printf("\n 2: Add a node at the beginning");
printf("\n 3: Add a node at the end");
printf("\n 4: Add a node before a given node");
printf("\n 5: Add a node after a given node");
printf("\n 6: Delete a node from the beginning");
printf("\n 7: Delete a node from the end");
printf("\n 8: Delete a node before a given node");
printf("\n 9: Delete a node after a given node");
printf("\n 10: Delete the node with a specific value");
printf("\n 0: EXIT");
printf("\n\n Enter your option : ");
scanf("%d", &option);
switch(option)
{
case 1: start = createLinkedlist();
break;
case 2: start = insertAtBeginning();
break;
case 3: start = insertAtEnd();
break;
case 4: start = insertBefore();
break;
case 5: start = insertAfter();
break;
case 6: start = deleteAtBeginning();
break;
case 7: start = deleteAtEnd();
break;
case 8: start = deleteBefore();
break;
case 9: start = deleteAfter();
break;
case 10: start = deleteNode();
}
}while(option != 0);
getch();
return 0;
}
struct node *createLinkedlist()
{
struct node *new_node, *ptr;
int num;
printf("\n Enter -1 to end");
printf("\n Enter the data : ");
scanf("%d", &num);
while(num != -1)
{
if(start == NULL)
{
new_node = (struct node*)malloc(sizeof(struct node));
new_node -> prev = NULL;
new_node -> data = num;
new_node -> next = NULL;
start = new_node;
}
else
{
ptr=start;
new_node = (struct node*)malloc(sizeof(struct node));
new_node -> data=num;
while(ptr -> next!=NULL)
ptr = ptr ->next;
ptr ->next = new_node;
new_node ->prev=ptr;
new_node ->next=NULL;
}
printf("\n Enter the data : ");
scanf("%d", &num);
}
display(start);
}
struct node *display(struct node *start)
{
printf("\nThe Linked List is:\n");
struct node *ptr;
ptr=start;
if(ptr == NULL)
 {
 printf("\nList is empty\n");
 }
 else
 {
while(ptr!=NULL)
{
printf("\t %d", ptr -> data);
ptr = ptr -> next;
}
return start;
}}
struct node *insertAtBeginning()
{
struct node *new_node;
int num;
printf("\n Enter the data to be inserted : ");
scanf("%d", &num);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
start -> prev = new_node;
new_node -> next = start;
new_node -> prev = NULL;
start = new_node;
display(start);
}
struct node *insertAtEnd()
{
struct node *ptr, *new_node;
int num;
printf("\n Enter the data to be inserted: ");
scanf("%d", &num);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
ptr=start;
while(ptr -> next != NULL)
ptr = ptr -> next;
ptr -> next = new_node;
new_node -> prev = ptr;
new_node -> next = NULL;
display(start);
}
struct node *insertBefore()
{
struct node *new_node, *ptr;
int num, val;
printf("\n Enter the data value which has to be inserted : ");
scanf("%d", &num);
printf("\n Enter the value before which the data has to be inserted:");
scanf("%d", &val);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
ptr = start;
while(ptr -> data != val && ptr!=NULL)
ptr = ptr -> next;
new_node -> next = ptr;
new_node -> prev = ptr -> prev;
ptr -> prev -> next = new_node;
ptr -> prev = new_node;
display(start);
}
struct node *insertAfter()
{
 struct node *new_node, *ptr;
 int num, val;
 printf("\n Enter the data value which has to be inserted : ");
 scanf("%d", &num);
 printf("\n Enter the value after which the data has to be inserted:");
 scanf("%d", &val);
 new_node = (struct node *)malloc(sizeof(struct node));
 new_node -> data = num;
 ptr = start;
 while(ptr -> data != val && ptr!=NULL )
 {
 ptr = ptr -> next;
 }
 if(ptr->next!=NULL)
 {
 (ptr->next)->prev=new_node;
 new_node->next=ptr->next;
 ptr->next=new_node;
 new_node->prev=ptr;
 }
 else
 {
 new_node -> next=NULL;
 new_node ->prev=ptr;
 ptr->next=new_node;
 }
 display(start);
}
struct node *deleteAtBeginning()
{
struct node *ptr;
ptr = start;
start = start -> next;
start -> prev = NULL;
free(ptr);
display(start);
}
struct node *deleteAtEnd()
{
struct node *ptr;
ptr = start;
while(ptr -> next != NULL)
ptr = ptr -> next;
ptr -> prev -> next = NULL;
free(ptr);
display(start);
}
struct node *deleteAfter()
{
struct node *ptr, *temp;
int val;
printf("\n Enter the value after which the node has to deleted : ");
scanf("%d", &val);
ptr = start;
while(ptr -> data != val && ptr!=NULL)
ptr = ptr -> next;
temp = ptr -> next;
ptr -> next = temp -> next;
temp -> next -> prev = ptr;
free(temp);
display(start);
}
struct node *deleteBefore()
{
struct node *ptr, *temp;
int val;
printf("\n Enter the value before which the node has to deleted:");
scanf("%d", &val);
ptr = start;
while(ptr -> data != val && ptr!=NULL)
ptr = ptr -> next;
temp = ptr -> prev;
if(temp == start)
start = deleteAtBeginning();
else
{
ptr -> prev = temp -> prev;
temp -> prev -> next = ptr;
}
free(temp);
display(start);
}
struct node *deleteNode()
{
struct node *ptr, *preptr;
int val;
printf("\n Enter the specific value in the node which has to be deleted : ");
scanf("%d", &val);
ptr = start;
if(ptr -> data == val)
{
start = deleteAtBeginning();
display(start);
}
else
{
while(ptr -> data != val && ptr!=NULL)
{
preptr = ptr;
ptr = ptr -> next;
}
preptr -> next = ptr -> next;
free(ptr);
display(start);
}
}

