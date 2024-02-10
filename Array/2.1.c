/*
Ques Description : (2.1)
WAP to create a 1-D array of n elements and perform the following menu based operations using function.
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array
*/

#include <stdio.h>
#include <stdlib.h>
int *create(int n);                 // Function to Create Array of Size n.
void create_new(int *arr, int *n);  // Function to realloacte array of new size
void insert(int *ptr);              // Function to insert elements in an array.
void delete(int *ptr);              // Function to Delete an Element.
void linearsearch(int *ptr, int n); // Function to find element by linear search.
void traverse(int arr[], int n);    // Function to traverse through the array.

int n = 0; // Initialising Number of Elements in Array or Size of Array.

int main()
{
    int a = 0, e = 1; // Initialising Variables n,a,e which represents Number of elements,Choice of option & Selector Respectively.
    printf("Enter Number of Elements : ");
    scanf("%d", &n);
    int *arr = create(n);
    printf("Enter Array Elements : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("MENU : 1. Insert 2. Delete 3. Linear Search 4. Traverse 5. Exit\n");
    do
    {
        printf("Enter option : ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            insert(arr);
            break;
        case 2:
            delete (arr);
            break;
        case 3:
            linearsearch(arr, n);
            break;
        case 4:
            traverse(arr, n);
            break;
        case 5:
            e = 0;
        }
    } while (e);
    printf("\nThank You ! ");
    return 0;
}

int *create(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr)
    {
        return arr;
    }
    else
    {
        printf("Memory Allocation Failed, Try Again !\n");
    }
}

void create_new(int *arr, int *n)
{
    arr = realloc(arr, (*n) * sizeof(int));
    if (arr == NULL)
    {
        printf("\nReallocation Failed !\nEnter Option 5 to Exit.\n");
    }
}

void insert(int *ptr) // Insert function definition
{
    int pos = 0, num = 0, temp1 = 0;
    printf("Position (1 to %d): ", n + 1);
    scanf("%d", &pos);
    if (pos >= 1 && pos <= n + 1)
    {
        printf("Element : ");
        scanf("%d", &num);
        n++;
        create_new(ptr, &n);
        // ptr += (pos - 1);
        if (*(ptr + (pos - 1)))
        {
            temp1 = *(ptr + (pos - 1));
            *(ptr + (pos - 1)) = num;
            for (int i = n; i > pos; i--)
            {
                *(ptr + i) = *(ptr + (i - 1));
            }
            *(ptr + pos) = temp1;
        }
        else
        {
            *ptr = num;
        }

        if (*(ptr + (pos - 1)) == num)
        {
            printf("%d inserted !\n", num);
        }
        else
        {
            printf("Element Not inserted !\n");
        }
    }
    else
    {
        printf("Position out of Array Bounds !\n");
    }
}

void delete(int *ptr) // Function to Delete (omit) an element in an Array
{
    int m = 0, c = 0, loc = -1;
    printf("Enter Element to Delete : ");
    scanf("%d", &m);
    for (int i = 0; i < n; i++)
    {
        if (*(ptr + i) == m)
        {
            //*(ptr + i) = 0;
            // printf("%d Deleted !\n", m);
            c = 1;
            loc = i;
        }
    }
    if (loc < n - 1 && loc != (-1))
    {
        printf("Element %d Deleted !\n", *(ptr + loc));
        for (int i = loc; i < n; i++)
        {
            *(ptr + i) = *(ptr + (i + 1));
        }
        *(ptr + (n - 1)) = 0;
        n--;
        create_new(ptr, &n);
    }
    else if (loc == n - 1)
    {
        printf("Element %d Deleted !\n", *(ptr + loc));
        *(ptr + loc) = 0;
        n--;
        create_new(ptr, &n);
    }
    else if (c == 0)
    {
        printf("Element not found !\n");
    }
}

void linearsearch(int *ptr, int n)
{
    int s = 0;
    printf("Enter element to search: ");
    scanf("%d", &s);
    for (int i = 0; i < n; i++)
    {
        if (*(ptr + i) == s)
        {
            printf("%d Found at index %d, Position : %d !!\n", s, i, i + 1);
            s = 0;
        }
    }
    if (s)
    {
        printf("%d Not found !\n", s);
    }
}

void traverse(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}
