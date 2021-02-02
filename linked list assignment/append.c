#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *var;
};
struct node *create_list(struct node *);
struct node *concat( struct node *list1,struct node *list2);
void display(struct node *start);
int main()
{
 struct node *list1=NULL,*list2=NULL;
 list1=create_list(list1);
 list2=create_list(list2);
 printf("\nFirst list is : ");
 display(list1);
 printf("\nSecond list is : ");
 display(list2);
 list1=concat(list1, list2);
 printf("\nConcatenated list is : ");
 display(list1);
 return 0;
}
struct node *concat( struct node *list1,struct node *list2)
{
 struct node *ptr;
 if(list1==NULL)
 {
 list1=list2;
 return list1;
 }
 if(list2==NULL)
 return list1;
 ptr=list1;
 while(ptr->var!=NULL)
 ptr=ptr->var;
 ptr->var=list2;
 return list1;
}
struct node *create_list(struct node *start)
{
 int i,n,val;
 printf("\nEnter the number of nodes in the linked list: ");
 scanf("%d",&n);
 start=NULL;
 if(n==0)
 return start;
 printf("Enter the data of node 1 : ");
 scanf("%d",&val);
 struct node *tmp;
 tmp=(struct node *)malloc(sizeof(struct node));
 tmp->data=val;
 tmp->var=start;
 start=tmp;
 for(i=2;i<=n;i++)
 {
 printf("Enter the data of node %d : ",i);
 scanf("%d",&val);
 struct node *value,*tmp;
 tmp= (struct node *)malloc(sizeof(struct node));
 tmp->data=val;
 value=start;
 while(value->var!=NULL)
 value=value->var;
 value->var=tmp;
 tmp->var=NULL;
 }
 return start;
}
void display(struct node *start)
{
 struct node *value;
 if(start==NULL)
 {
 printf("\nList is empty\n");
 return;
 }
 value=start;
 while(value!=NULL)
 {
 printf("%d ", value->data);
 value=value->var;
 }
 printf("\n");
}
