#include <stdio.h>

int transpose(int arr[100][100], int a, int b)
{
	int c, d, transpose[100][100];
	
	for (c = 0; c < a; c++)
    for (d = 0; d < b; d++)
      transpose[d][c] = arr[c][d];
 
  printf("Transpose of the matrix:\n");
 
  for (c = 0; c < b; c++) {
    for (d = 0; d < a; d++)
      printf("%d ", transpose[c][d]);
    printf("\n");
  }
}
 
int main()
{
  int m, n, i, j, matrix[100][100];
 
  printf("Enter the number of rows and columns of a matrix\n");
  scanf("%d%d", &m, &n);
  
  printf("Enter elements of the matrix\n");
 
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &matrix[i][j]);
      
  printf("The main matrix:\n");
  
  for  (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
    {
	  printf("%d ", matrix[i][j]);  
	  
	  if (j == n-1)
	  printf("\n");
    }
 
  transpose(matrix, m, n);

  return 0;
}


 

