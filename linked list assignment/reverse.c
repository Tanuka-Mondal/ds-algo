#include<stdio.h>
#include<stdlib.h>
void createList(int n);
void reverseList();
void display();
struct node {
int val;
struct node *ptrnext;
}*start;
void reverseList()
{
struct node *ptr = start;
struct node *prevptr = NULL, *ptrnext = NULL;
while (ptr != NULL)
{
ptrnext = ptr->ptrnext;
ptr->ptrnext = prevptr;
prevptr = ptr;
ptr = ptrnext;
}
start = prevptr;
}
void createList(int n)
{
struct node *newNode, *tmp;
int val, i;
start = (struct node *)malloc(sizeof(struct node));
if(start == NULL)
{
printf("Unable to allocate memory.");
}
else
{
printf("\nEnter the data of node 1: ");
scanf("%d", &val);
start->val = val;
start->ptrnext = NULL;
tmp = start;
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
printf("\nEnter the data of node %d: ", i);
scanf("%d", &val);
newNode->val = val;
newNode->ptrnext = NULL;
tmp->ptrnext = newNode;
tmp = tmp->ptrnext;
}}}}
void display()
{
struct node *tmp;
if(start == NULL)
{
printf("List is empty.");
}
else
{
tmp = start;
while(tmp != NULL)
{
printf("%d\t", tmp->val);
tmp = tmp->ptrnext;
}
printf("\n");
}}
int main()
{
int n;
printf("\nEnter the number of nodes in the linked list: ");
scanf("%d", &n);
createList(n);
printf("\nThe Linked List is: \n");
display();
printf("\nThe Reversed Linked List is:\n");
reverseList();
display();
return 0;
}

