
#include <stdio.h>

int copy(int arr[],int num)
{
	int arr2[100],i;
	
	for(i=0; i<num; i++)
    {
        arr2[i] = arr[i];
    }
    
    printf("\nElements of 1st array are : ");
    for(i=0; i<num; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n\nElements of copied array are : ");
    for(i=0; i<num; i++)
    {
        printf("%d ", arr2[i]);
    }
}

int main()
{
    int array[100];
    int i, size;

    /* Input size of the array */
    printf("Enter the size of the array : \n");
    scanf("%d", &size);
    
    /* Input array elements */
    printf("\nEnter elements of the array : \n");
    for(i=0; i<size; i++)
    {
        scanf("%d", &array[i]);
    }
    
    copy(array,size);
  

    return 0;
}
