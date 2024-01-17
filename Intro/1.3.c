/*
Ques Description : (1.3) 
Write a program to create a structure to store the information of n number of Employees. 
Employee’s information includes data members: Emp-id, Name, Designation, basic_salary, hra%, da%. 
Display the information of employees with gross salary. Use array of structure.
*/

#include <stdio.h>

typedef struct emp
{
    char name[100];
    char desig[100];
    int sal;
    int hra;
    int da;
} emp;

void create();

int main()
{
    int n = 0; // Initialising the number of employees to zero.
    printf("Enter Number of Employees : ");
    scanf("%d", &n);
    emp rec[100];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Info for Person : %d", i);
        printf("Enter Name : ");
        scanf("%s", &rec[i].name);
        printf("Enter Designation : ");
        scanf("%s", &rec[i].desig);
        printf("Enter Salary : ");
        scanf("%s", &rec[i].sal);
        printf("Enter HRA : ");
        scanf("%s", &rec[i].hra);
        printf("Enter DA : ");
        scanf("%s", &rec[i].da);
    }
}