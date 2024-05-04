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
    char desig[50];
    float sal;
    float hra;
    float da;
} emp;

int main()
{
    int n = 0; // Initialising the number of employees to zero.
    printf("Enter Number of Employees : ");
    scanf("%d", &n);
    emp rec[10]; //Initialising the array of employee structure to 10 at max.
    for (int i = 0; i < n; i++)
    {
        printf("Enter Info for Person : %d\n", i);
        printf("Enter Name : ");
        scanf("%s", &rec[i].name);
        printf("Enter Designation : ");
        scanf("%s", &rec[i].desig);
        printf("Enter Salary : ");
        scanf("%f", &rec[i].sal);
        printf("Enter HRA : ");
        scanf("%f", &rec[i].hra);
        printf("Enter DA : ");
        scanf("%f", &rec[i].da);
    }

    printf("\nEmployee Info : \n");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        printf("Name : %s\n", rec[i].name);
        printf("Designation : %s\n", rec[i].desig);
        printf("Salary : %f\n", rec[i].sal);
        printf("HRA : %f\n", rec[i].hra);
        printf("DA : %f\n", rec[i].da);
        printf("Gross Salary : %f\n", rec[i].sal + (rec[i].sal * rec[i].hra / 100) + (rec[i].sal * rec[i].da / 100));
        printf("\n");
    }
}