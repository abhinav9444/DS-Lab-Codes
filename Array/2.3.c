/*
Ques Description : (2.3)
Write a Program to represent a given sparse matrix in 3-tuple format using 2-D array.
*/

#include <stdio.h>
#include <stdlib.h>
int n;                               // Global variable to store the size of the matrix.
int is_sparse(int mat[n][n], int n); // Function to check whether a matix is sparse or not.
int main()
{
    printf("Enter the size of the square matrix: (n) : ");
    scanf("%d", &n);
    int mat[n][n];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            printf("Enter element at position (%d, %d): ", i, j);
            scanf("%d", &mat[i][j]);
        }
    if (is_sparse(mat, n))
    {
        printf("The Sparse matrix is:\n R \tC \tE\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] != 0)
                    printf(" %d \t%d \t%d\n", i, j, mat[i][j]);
            }
        }
    }
    else
    {
        printf("The matrix is not sparse\n");
    }
    return 0;
}

int is_sparse(int mat[n][n], int n)
{
    int count_zero = 0;
    int total_elements = n * n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!mat[i][j])
            {
                count_zero++;
            }
    if (count_zero > (total_elements / 2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}