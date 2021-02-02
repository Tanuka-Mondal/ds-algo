#include <stdio.h>

int insert(int arr[], int num, int pos, int val)
{
	int i;
	for (i = num - 1; i >= pos - 1; i--) 
	  arr[i+1] = arr[i];
    
    arr[pos-1] = val;
    
    printf("\nResultant array is\n");
    
    for (i = 0; i <= num; i++)    
    printf("%d ", arr[i]);    
    
}

int main()
{
    int array[100], position, i, n, value;
    
    printf("Enter number of elements in the array\n");
    scanf("%d", &n);
    
    printf("\nEnter %d elements\n", n);
    
    for (i = 0; i < n; i++)    
    scanf("%d", &array[i]);
    
    printf("\nPlease enter the location where you want to insert an new element\n");
    scanf("%d", &position);
    
    printf("\nPlease enter the value\n");
    scanf("%d", &value);
    
    insert(array, n, position, value);
    
    
    return 0;
}
