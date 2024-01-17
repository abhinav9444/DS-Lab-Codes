/*
Ques Description : (1.1) Write a program to read two numbers and compare the numbers using function call by address.
*/

#include <stdio.h>
void comp(int *x, int *y);
int main()
{
    int a = 0, b = 0;
    printf("Enter numbers 1 : ");
    scanf("%d", &a);
    printf("Enter numbers 2 : ");
    scanf("%d", &b); // Taking two number inputs
    comp(&a, &b);    // Passing address of the two variables as arguements for comparison.
    return 0;
}

void comp(int *x, int *y)
{
    if (*x > *y)
    {
        printf("%d is greater than %d", *x, *y);
    }
    else if (*x == *y)
    {
        printf("Both numbers are equal.");
    }
    else
    {
        printf("%d is smaller than %d", *x, *y);
    }
}