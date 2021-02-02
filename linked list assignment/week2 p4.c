#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
 int data;
 struct node *next;
 struct node *prev;
}*start;
void create(int );
void deleteNode(int ,int );
void print();
int main()
{
 int num,n,m;
 printf("\nEnter the number of nodes in linked list: ");
 scanf("%d",&num);
 create(num);
 printf("\nThe Linked List is: \n");
 print();
 printf("\nEnter the node after which you want to delete nodes: ");
 scanf("%d",&m);
 printf("\nEnter no. of nodes you want to delete: ");
 scanf("%d",&n);
 printf("\nThe Linked List after deleting the nodes : \n");
 deleteNode(n,m);
 print();
 return 0;
}
void create(int n)
{
 struct node *ptr, *temp;
 int data, i;
 start = (struct node *)malloc(sizeof(struct node));
 if(start == NULL)
 {
 printf("\nList is empty.\n");
 }
 else
 {
 printf("\nEnter the data of node 1: ");
 scanf("%d", &data);
 start->data = data;
 start->next = NULL;
 temp = start;
 for(i=2; i<=n; i++)
 {
 ptr = (struct node *)malloc(sizeof(struct node));
 if(ptr == NULL)
 {
 printf("\nList is empty.\n");
 break;
 }
 else
 {
 printf("Enter the data of node %d: ",i);
 scanf("%d", &data);
 ptr->data = data;
 ptr->next = NULL;
 temp->next = ptr;
 temp = temp->next;
 }
 }
 }
}
void deleteNode(int n, int m)
{
 if(start==NULL)
 {
 printf("\nThe list is empty. Operation can not be performed.\n");
 }
 else
 {
 struct node *ptr,*temp;
 ptr= start;
 while(m !=1 && ptr!=NULL)
 {
 ptr=ptr->next;
 m--;
 }
 if(ptr==NULL)
 {
 printf("\nThe operation can not be performed.\n");
 }
 else if(ptr->next!=NULL)
 {
 while(n!=0 && ptr->next != NULL)
 {
 temp=ptr->next;
 ptr->next=temp->next;
 (temp->next)->prev=ptr;
 free(temp);
 n--;
 }
 }
 }
}
void print()
{
 struct node *ptr;
 if(start == NULL)
 {
 printf("\nList is empty\n");
 }
 else
 {
 ptr=start;
 while(ptr != NULL)
 {
 printf("\t %d", ptr -> data);
 ptr = ptr -> next;
 }
 }
}
