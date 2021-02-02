#include<stdio.h>

int delnum(int arr[], int n, int x)
{
  int i,j;
  for (i=0; i<n; i++) 
  if (arr[i] == x)
  break;
if (i < n) 
{
  n = n - 1;
  
  for(j=i; j<n; j++)
  arr[j] = arr[j+1];
}
return n;
}
void main()
{
  int array[100],i,n,x;
  printf("Enter number of elements in array: \n"); 
  scanf("%d",&n);
  printf("Enter %d elements: \n",n);
  for(i=0;i<n;i++) 
  scanf("%d",&array[i]);
  printf("Enter the element that you wish to delete: \n"); 
  scanf("%d",&x);
  n = delnum(array, n, x);
  printf("The updated array: \n"); 
  for(i=0;i<n;i++)
  printf("%d ",array[i]);
  getch();
}
