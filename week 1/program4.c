#include <stdio.h>

int largest(int arr[],int num)
{
	int i, j, large, temp;
	for (i = 1; i < num; ++i) 
	{
        if (arr[0] < arr[i])
        {
            temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            
        }
        large = arr[0];
    }
    
    for (j = 1; j < num-1; ++j)
    {
    	if (arr[1] < arr[j])
    	arr[1] = arr[j];
	}
    printf("\nLargest element = %d" , large);
    printf("\n\nSecond largest element = %d", arr[1]);
}

int main() {
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

   largest(array,size);
    return 0;
}
