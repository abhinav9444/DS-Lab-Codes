/*
Ques Description : (2.1)
Write a program to perform the following operations on a given square matrix using functions:
i.   Find the no.of nonzero elements
ii.  Display upper triangular matrix
iii. Display the elements of just above and below the main diagonal
*/

#include <stdio.h>
#include <stdlib.h>
int countNonZero(int **mat, int n);      // Function to find the number of nonzero elements in the matrix.
void dispupTriangular(int **mat, int n); // Function to display the upper triangular matrix.
void dispNearDiagonal(int **mat, int n); // Function to display elements just above and below the main diagonal.
int **create_sq_matrix(int n);           // Function to create square matrix of size n
int main()
{
    int n, s = 1, a = 0;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);
    int **mat;
    mat = create_sq_matrix(n);
    if (mat == NULL)
    {
        return 0;
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);
    printf("1. No. of Non- Zero Elements\t2. Display Upper Triangular Matrix\t3.Display Elements just above and below the main digonal 4. Exit\n");
    do
    {
        printf("Enter Option : ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Number of nonzero elements: %d\n", countNonZero(mat, n));
            break;
        case 2:
            dispupTriangular(mat, n);
            break;
        case 3:
            dispNearDiagonal(mat, n);
            break;
        case 4:
            s = 0;
            break;
        default:
            printf("Invalid Option !\n");
        }
    } while (s);
    printf("\nThank You !");
    return 0;
}

int countNonZero(int **mat, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] != 0)
                count++;
    return count;
}

void dispupTriangular(int **mat, int n)
{
    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i)
                printf("0\t");
            else
                printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void dispNearDiagonal(int **mat, int n)
{
    printf("Elements just above and below the main diagonal:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                printf("%d\t", mat[i][j]);
            else
                printf("0\t");
        }
        printf("\n");
    }
}

int **create_sq_matrix(int n)
{
    int **mat;
    mat = (int **)malloc(n * sizeof(int *));
    if (mat == NULL)
    {
        printf("Memory allocation failed !\n");
        return NULL; // Exit program
    }

    // Allocate memory for each row
    for (int i = 0; i < n; i++)
    {
        mat[i] = (int *)malloc(n * sizeof(int));
        if (mat[i] == NULL)
        {
            printf("Memory allocation failed\n");
            for (int j = 0; j < i; j++)
            {
                free(mat[j]);
            }
            free(mat);
            return NULL; // Exit program
        }
    }
    return mat;
}