/*
Ques Description : (3.1)
WAP to perform transpose of a given sparse matrix in 3-tuple format.
*/

#include <stdio.h>
#include <stdlib.h>

int n;                                               // Global variable to store the size of the matrix.
void transpose(int r[n], int c[n], int e[n], int n); // Function to perform the transpose of the matrix.
int main()
{
    printf("Enter the size of the square matrix: (n) : ");
    scanf("%d", &n);
    int r[n], c[n], e[n];
    printf("Enter the number of non-zero elements in the matrix: ");
    int nz;
    scanf("%d", &nz);
    printf("Enter the 3-tuple format of the matrix:\n");
    for (int i = 0; i < nz; i++)
    {
        printf("Enter the row, column and element at position %d: ", i + 1);
        scanf("%d %d %d", &r[i], &c[i], &e[i]);
    }
    printf("The original matrix is:\n R \tC \tE\n");
    for (int i = 0; i < nz; i++)
    {
        printf(" %d \t%d \t%d\n", r[i], c[i], e[i]);
    }
    transpose(r, c, e, nz);
    return 0;
}

void transpose(int r[n], int c[n], int e[n], int n)
{
    int t_r[n], t_c[n], t_e[n];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        t_r[k] = c[i];
        t_c[k] = r[i];
        t_e[k] = e[i];
        k++;
    }
    printf("The transpose of the matrix is:\n R \tC \tE\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d \t%d \t%d\n", t_r[i], t_c[i], t_e[i]);
    }
}
