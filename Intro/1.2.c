/*
Ques Description : (1.2)
Write a program to create an array of n elements using dynamic memory allocation. Calculate
sum of all the prime elements of the array using function and de-allocate the memory of the array after its use.
*/

#include <stdio.h>
#include <stdlib.h>
int prime(int a);          // Function to check whether number is Prime or not.
void sum(int *ptr, int n); // Function to calculate the sum of Numbers.
int main()
{
    int n = 0;
    printf("Enter number of Elements : ");
    scanf("%d", &n);
    int *ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Index : %d : ", i);
        scanf("%d", &ptr[i]);
    }
    sum(ptr, n);
    free(ptr);
    return 0;
}

int prime(int a)
{
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void sum(int *ptr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (prime(ptr[i]))
        {
            sum += ptr[i];
        }
    }
    printf("Sum of Prime Elements : %d", sum);
}
