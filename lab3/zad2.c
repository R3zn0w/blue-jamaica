#include <stdio.h>

void printTableInt(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf(" %d ", arr[i]);
    printf("\n");
}
void printTableDouble(double arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf(" %f ", arr[i]);
    printf("\n");
}
void printPointersInt(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf(" %d ", &arr[i]);
    printf("\n");
}
void printPointersDouble(double arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf(" %d ", &arr[i]);
    printf("\n");
}

int main()
{
    int arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, *ptr1;
    double arr2[10] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0}, *ptr2;

    printTableInt(arr1, 10);
    printPointersInt(arr1, 10);
    printTableDouble(arr2, 10);
    printPointersDouble(arr2, 10);
    ptr1 = arr1;
    ptr2 = arr2;
    printTableInt(ptr1, 10);
    printPointersInt(ptr1, 10);
    printTableDouble(ptr2, 10);
    printPointersDouble(ptr2, 10);
    return 0;
}