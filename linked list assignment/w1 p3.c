#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
int data;
struct node *next;
};
struct node *start = NULL;
struct node *create_circularLinkedList();
struct node *display(struct node *);
struct node *insert_beginning();
struct node *insert_end();
struct node *insert_after();
struct node *insert_before();
struct node *delete_beginning();
struct node *delete_end();
struct node *delete_after();
struct node *delete_before();
struct node *delete_node();
int main()
{
int choice;
do
{
printf("\n\n ENTER YOUR CHOICE");
printf("\n 1: Create a Circular Linked list");
printf("\n 2: Insert a node at the beginning");
printf("\n 3: Insert a node at the end");
printf("\n 4: Insert a node after a given node with specific value");
printf("\n 5: Insert a node before a given node with specific value");
printf("\n 6: Delete a node from the beginning.");
printf("\n 7: Delete a node from the end");
printf("\n 8: Delete a node after a given node with specific value");
printf("\n 9: Delete a node before a given node with specific value");
printf("\n 10: Delete a node with a specific value");
printf("\n 0: EXIT");
printf("\n\n Enter your option : ");
scanf("%d", &choice);
switch(choice)
{
case 1: start = create_circularLinkedList();
break;
case 2: start = insert_beginning();
break;
case 3: start = insert_end();
break;
case 4: start = insert_after();
break;
case 5: start = insert_before();
break;
case 6: start = delete_beginning();
break;
case 7: start = delete_end();
break;
case 8: start = delete_after();
break;
 case 9: start = delete_before();
break;
case 10: start = delete_node();
break;
}
}while(choice !=0);
getch();
 return 0;
}
struct node *create_circularLinkedList()
{
struct node *new_node, *ptr;
int num;
printf("\n Enter -1 to end");
printf("\n Enter the data in the circular linked list: ");
scanf("%d", &num);
while(num!=-1)
{
new_node = (struct node*)malloc(sizeof(struct node));
new_node -> data = num;
if(start == NULL)
{
new_node -> next = new_node;
start = new_node;
}
else
{ ptr = start;
while(ptr -> next != start && ptr!=NULL)
ptr = ptr -> next;
ptr -> next = new_node;
new_node -> next = start;
}
printf("\n Enter the data in the circular linked list : ");
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
while(ptr -> next != start && ptr!=NULL)
{
printf("\t %d", ptr -> data);
ptr = ptr -> next;
}
printf("\t %d", ptr -> data);
return start;
}}
struct node *insert_beginning()
{
struct node *new_node, *ptr;
int num;
printf("\n Enter the data value which has to be inserted in the beginning: ");
scanf("%d", &num);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
ptr = start;
while(ptr -> next != start && ptr!=NULL)
ptr = ptr -> next;
ptr -> next = new_node;
new_node -> next = start;
start = new_node;
display(start);
}
struct node *insert_end()
{
struct node *ptr, *new_node;
int num;
printf("\n Enter the data value which has to be inserted in the end :");
scanf("%d", &num);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
ptr = start;
while(ptr -> next != start && ptr!=NULL)
ptr = ptr -> next;
ptr -> next = new_node;
new_node -> next = start;
display(start);
}
struct node *insert_after()
{
struct node *new_node, *ptr, *preptr;
int num, val;
printf("\n Enter the data value which has to be inserted :");
scanf("%d", &num);
printf("\n Enter the value after which the data has to be inserted :");
scanf("%d", &val);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
ptr = start;
preptr = ptr;
while(preptr -> data != val && ptr!=NULL)
{
preptr = ptr;
ptr = ptr -> next;
}
preptr -> next=new_node;
new_node -> next = ptr;
display(start);
}
struct node *insert_before()
{
struct node *new_node, *ptr, *preptr;
int num, val;
printf("\n Enter the data value which has to be inserted :");
scanf("%d", &num);
printf("\n Enter the value before which the data has to be inserted :");
scanf("%d", &val);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
ptr = start;
while(ptr -> data != val && ptr!=NULL)
{
preptr = ptr;
ptr = ptr -> next;
}
preptr -> next = new_node;
new_node -> next = ptr;
display(start);
}
struct node *delete_beginning()
{
struct node *ptr;
ptr = start;
while(ptr -> next != start && ptr!=NULL)
ptr = ptr -> next;
ptr -> next = start -> next;
free(start);
start = ptr -> next;
display(start);
}
struct node *delete_end()
{
struct node *ptr, *preptr;
ptr = start;
while(ptr -> next != start && ptr!=NULL)
{
preptr = ptr;
ptr = ptr -> next;
}
preptr -> next = ptr -> next;
free(ptr);
display(start);
}
struct node *delete_after()
{
struct node *ptr, *preptr;
int val;
printf("\n Enter the data value after which the node has to deleted : ");
scanf("%d", &val);
ptr = start;
preptr = ptr;
while(preptr -> data != val && ptr!=NULL)
{
preptr = ptr;
ptr = ptr -> next;
}
preptr -> next = ptr -> next;
if(ptr == start)
start = preptr -> next;
free(ptr);
display(start);
}
struct node *delete_before()
{
struct node *ptr, *preptr;
int val;
printf("\n Enter the data value before which the node has to deleted :");
scanf("%d", &val);
ptr = start;
preptr = ptr;
while(ptr -> data != val && ptr!=NULL)
{
preptr = ptr;
ptr = ptr -> next;
}
preptr->data=ptr->data;
preptr->next=ptr->next;
free(ptr);
display(start);
}
struct node *delete_node()
{
struct node *ptr, *preptr;
int val;
printf("\n Enter the specific value in the node which has to be deleted : ");
scanf("%d", &val);
ptr = start;
if(ptr -> data == val)
{
start = delete_beginning();
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
