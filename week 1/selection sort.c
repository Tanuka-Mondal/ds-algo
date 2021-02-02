#include <stdio.h>
int main()
{
int arr[100], num, i, j, pos, temp;
printf("Enter the number of elements\n");
scanf("%d", &num);
printf("Enter the elements\n");
for (i = 0; i < num; i++)
scanf("%d", &arr[i]);
printf("The array is \n");
    for (i = 0; i < num; i++)
    {
        printf("%d  ", arr[i]);
    }

for(i = 0; i < num - 1; i++)
{
pos=i;
for(j = i + 1; j < num; j++)
{
if(arr[pos] > arr[j])
pos=j;
}
if(pos != i)
{
temp=arr[i];
arr[i]=arr[pos];
arr[pos]=temp;
}
}
printf("\nSorted Array:\n");
for(i = 0; i < num; i++)
printf("%d  ", arr[i]);
return 0;
}



