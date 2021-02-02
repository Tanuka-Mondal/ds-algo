#include <stdio.h>

int del(int arr[], int num, int pos)
{
	int i;
	
	if (pos >= num+1)
      printf("Deletion not possible.\n");
   else
   {
      for (i = pos - 1; i < num - 1; i++)
         arr[i] = arr[i+1];

      printf("\nResultant array:\n");

      for (i = 0; i < num - 1; i++)
         printf("%d ", arr[i]);
   }
}

int main()
{
   int array[100], position, c, n;

   printf("Enter number of elements in array\n");
   scanf("%d", &n);

   printf("\nEnter %d elements\n", n);

   for (c = 0; c < n; c++)
      scanf("%d", &array[c]);

   printf("\nEnter the location where you wish to delete element\n");
   scanf("%d", &position);
   
   del(array, n, position);

   return 0;
}
