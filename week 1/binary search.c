#include<stdio.h>
  int main()
  {
  int  arr[100],i,n,x,f,l,m,flag=0;
  printf("Enter the number of elements\n");
  scanf("%d",&n);
  printf("Input  %d value in ascending order\n",n);
  for(i=0;i<n;i++)
  scanf("%d",&arr[i]);
  printf("Input  the value to be search : ");
  scanf("%d",&x);
 
  f=0;l=n-1;
  while(f<=l)
  {
  m=(f+l)/2;
  if(x==arr[m])
  {
  flag=1;
  break;
  }
  else  if(x<arr[m])
  l=m-1;
  else
  f=m+1;
  }
  if(flag==0)
  printf("%d  value not found\n",x);
  else
  printf("%d value  found at index %d\n",x,m);
  }
