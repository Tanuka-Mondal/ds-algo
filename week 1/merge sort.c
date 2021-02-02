#include<stdio.h>
 
void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);

int main()
{
    int arr[100];
    int i, num;
 
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
    
    mergesort(arr,0,num-1);
    
       printf("\n\nArray after sorting\n");
    for (i = 0; i < num; i++)
    {
        printf("%d  ", arr[i]);
    }
}

void mergesort(int a[],int i,int j)
{
	int mid;
		
	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(a,i,mid);		//left recursion
		mergesort(a,mid+1,j);	//right recursion
		merge(a,i,mid,mid+1,j);	//merging of two sorted sub-arrays
	}
}
 
void merge(int a[],int i1,int j1,int i2,int j2)
{
	int temp[50];	
	int i,j,k;
	i=i1;	
	j=i2;	
	k=0;
	
	while(i<=j1 && j<=j2)	
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	
	while(i<=j1)	
		temp[k++]=a[i++];
		
	while(j<=j2)	
		temp[k++]=a[j++];
		
	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=temp[j];
}
