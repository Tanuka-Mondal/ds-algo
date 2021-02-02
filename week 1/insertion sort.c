#include <stdio.h>
 
int main()
{
    int arr[100];
    int i, j, num, temp, flag;
 
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
    
    
     for (i = 1 ; i <= num - 1; i++) {
    temp = arr[i];

    for (j = i - 1 ; j >= 0; j--) {
      if (arr[j] > temp) {
        arr[j+1] = arr[j];
        flag = 1;
      }
      else
        break;
    }
    if (flag)
      arr[j+1] = temp;
  }
  
    printf("\n\nArray after sorting\n");
    for (i = 0; i < num; i++)
    {
        printf("%d  ", arr[i]);
    }
}
