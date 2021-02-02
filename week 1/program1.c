
#include  <stdio.h>
 
int func(int array[], int value)
{
	float total = 0.0, avg;
	int i;
	for (i = 0; i < value; i++)
    {
        total+=array[i];
        
    }
    avg = total/value;
    
    printf("\n Sum of all numbers =  %.2f\n", total);
 
    printf("\n Average of all numbers =  %.2f\n", avg);
}

int main()
{
    int i, val;
    
    printf ("Enter the number of elements \n");
    scanf("%d", &val);
    int arr[val];
 
    printf("Enter %d numbers (-ve, +ve and zero) \n", val);
 
    for (i = 0; i < val; i++)
    {
        scanf("%d", &arr[i]);
    }
 
    printf("Input array elements \n");
 
    for (i = 0; i < val; i++)
    {
        printf("%+3d\n", arr[i]);
    }
 
 
    func(arr, val);
    
}


