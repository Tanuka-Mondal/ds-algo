#include<stdio.h>
int quicksort(int array[25],int first,int last){
   int i, j, flag, temp;

   if(first<last){
      flag=first;
      i=first;
      j=last;

      while(i<j){
         while(array[i]<=array[flag]&&i<last)
            i++;
         while(array[j]>array[flag])
            j--;
         if(i<j){
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
         }
      }

      temp=array[flag];
      array[flag]=array[j];
      array[j]=temp;
      quicksort(array,first,j-1);
      quicksort(array,j+1,last);

   }
}

int main(){
   int i, num, arr[25];

   printf("Enter the number of elements\n");
   scanf("%d",&num);

   printf("\nEnter the elements \n");
   for(i=0;i<num;i++)
      scanf("%d",&arr[i]);
      
    printf("\nThe array is \n");
    for (i = 0; i < num; i++)
    {
        printf("%d  ", arr[i]);
    }  

   quicksort(arr,0,num-1);

   printf("\n\nArray after sorting\n");
   for(i=0;i<num;i++)
      printf(" %d  ",arr[i]);

   return 0;
}

