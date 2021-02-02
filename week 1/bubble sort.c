#include <stdio.h>
 
int main()
{
    int arr[100];
    int i, j, num, temp;
 
    printf("Enter the number of elements\n");
    scanf("%d", &num);
    printf("\nEnter the elements \n");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nThe array is \n");
    for (i = 0; i < num; i++)
    {
        printf("%d  ", arr[i]);
    }
    

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < (num - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    
    printf("\n\nArray after sorting\n");
    for (i = 0; i < num; i++)
    {
        printf("%d  ", arr[i]);
    }
}
