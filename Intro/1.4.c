/*
Ques Description :
(1.4) Write a menu driven program to create a structure to represent complex number and perform the following operation using function :
1. addition of two complex number  (call by value)
2. multiplication of two complex number (call by address)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct complex // Defining Structure for Complex Number
{
    int real;
    int img;
} comp;
void add(comp x, comp y);   // Function to calculate the sum of complex numbers.
void mul(comp *x, comp *y); // Function to calculate the Product of complex numbers.

int main()
{
    comp x1, x2;
    printf("Enter Number 1 Real Part : ");
    scanf("%d", &x1.real);
    printf("Enter Number 1 img Part : ");
    scanf("%d", &x1.img);
    printf("Enter Number 2 Real Part : ");
    scanf("%d", &x2.real);
    printf("Enter Number 2 img Part : ");
    scanf("%d", &x2.img);
    printf("       ***MENU***\n1. Add two Complex Numbers\n2. Multiply two Complex Numbers\nEnter Option : ");
    int c;
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        add(x1, x2);
        break;
    case 2:
        mul(&x1, &x2);
        break;
    default:
        printf("Invalid Choice !\n");
    }
}

void add(comp x, comp y)
{
    comp sum;
    sum.real = x.real + y.real;
    sum.img = x.img + y.img;
    if (sum.img > 0)
        printf("Sum = %d+%di", sum.real, sum.img);
    else
        printf("Sum = %d%di", sum.real, sum.img);
}

void mul(comp *x, comp *y)
{
    comp prod;
    prod.real = (x->real * y->real) - (x->img * y->img);
    prod.img = (x->real * y->img) + (x->img * y->real);
    if (prod.img > 0)
        printf("Product = %d+%di", prod.real, prod.img);
    else
        printf("Product = %d%di", prod.real, prod.img);
}