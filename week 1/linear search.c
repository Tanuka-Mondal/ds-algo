#include<stdio.h>
  
int main()
{
    int arr[100],i,x,n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
     
    printf("\nEnter the elements:\n");
    for(i=0;i<n;++i)
        scanf("%d",&arr[i]);
     
    printf("\nEnter element to search\n");
    scanf("%d",&x);
     
    for(i=0;i<n;++i)
        if(arr[i]==x)
            break;
     
    if(i<n)
        printf("\nElement found at index %d",i);
    else
        printf("Element not found");
  
    return 0;
}
