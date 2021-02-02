#include <stdio.h>

int maxmin(int arr[],int num)
{
	int i, j, max, temp;
	for (i = 1; i < num; ++i) 
	{
        if (arr[0] < arr[i])
        {
            temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            
        }
        max = arr[0];
    }
    
    for (j = 1; j < num-1; ++j)
    {
    	if (arr[1] > arr[j])
    	arr[1] = arr[j];
	}
    printf("\nMaximum element = %d" , max);
    printf("\n\nMinimum element = %d", arr[1]);
}

int main() {
    int array[100];
    int i, size;

    printf("Enter the size of the array : \n");
    scanf("%d", &size);
    
    
    printf("\nEnter elements of the array : \n");
    for(i=0; i<size; i++)
    {
        scanf("%d", &array[i]);
    }

   maxmin(array,size);
    return 0;
}
