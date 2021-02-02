
#include<stdio.h>


int rverese(int arr[], int first, int last)
{
	int temp;
	while (first < last)
	{
		temp = arr[first]; 
		arr[first] = arr[last];
		arr[last] = temp;
		first++;
		last--;
	} 
}	 


int printarr(int arr[], int size)
{
int i;
for (i=0; i < size; i++)
	printf("%d ", arr[i]);

printf("\n");
} 


int main() 
{
	int val,i;
	printf ("Enter the number of elements \n");
    scanf("%d", &val);
    int arr[val];
 
    printf("\nEnter %d numbers (-ve, +ve and zero) \n", val);
 
    for (i = 0; i < val; i++)
    {
        scanf("%d", &arr[i]);
    }
 
   
    
	int n = sizeof(arr) / sizeof(arr[0]); 
	printf("\nThe array is\n");
	printarr(arr, n);
	rverese(arr, 0, n-1);
	printf("\nReversed array is \n");
	printarr(arr, n); 
	return 0;
}

