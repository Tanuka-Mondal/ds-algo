#include <stdio.h>

int add(int arr1[100][100], int arr2[100][100], int a, int b)
{
	int c, d, sum[100][100];
	
	for (c = 0; c < a; ++c)
        for (d = 0; d < b; ++d) {
            sum[c][d] = arr1[c][d] + arr2[c][d];
        }

    printf("\nSum of two matrices: \n");
    for (c = 0; c < a; ++c)
        for (d = 0; d < b; ++d) {
            printf("%d   ", sum[c][d]);
            if (d == b - 1) {
                printf("\n\n");
            }
        }
}
int main()
{
	int m, n, i, j, matrix1[100][100], matrix2[100][100] ;
	
	printf("Enter the number of rows and columns of a matrix\n");
    scanf("%d%d", &m, &n);
    
    printf("\nEnter elements of the 1st matrix\n");
 
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        scanf("%d", &matrix1[i][j]);
        
    printf("\nEnter elements of the 2nd matrix\n");
 
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        scanf("%d", &matrix2[i][j]);  
		
	add(matrix1, matrix2, m, n);
	
	return 0;	   
}
