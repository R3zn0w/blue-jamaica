#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp) //array elements swapping utility
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void fillRandom(int arr[], int n) //filling with random
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10; //range set to 0-9
}

void reverse(int arr[], int n) //array reversing
{
    for (int i = 0; i <= n / 2; i++)
        swap(&arr[i], &arr[n - i - 1]);
}

void sort(int arr[], int n) //array bubble sort
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int one_two(int arr1[], int n1, int arr2[], int n2, int arr3[], int n3)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] == arr3[k - 1] && k > 0)
        {
            i++;
            continue;
        }
        else if (arr2[j] == arr3[k - 1] && k > 0)
        {
            j++;
            continue;
        }

        else if (arr1[i] <= arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        if (arr1[i] == arr3[k - 1])
        {
            i++;
            continue;
        }
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        if (arr2[j] == arr3[k - 1])
        {
            j++;
            continue;
        }
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    return k;
}

void printTable(int arr[], int n) //array print utility
{
    for (int i = 0; i < n; i++)
        printf(" %d ", arr[i]);
    printf("\n");
}

int main()
{
    int n = 10;
    int t1[10], t2[10], t3[20];
    srand(time(0));
    fillRandom(t1, n);
    fillRandom(t2, n);
    printf("Randomly generated tables: \n");
    printTable(t1, n);
    printTable(t2, n);
    reverse(t1, n);
    reverse(t2, n);
    printf("Reversed tables: \n");
    printTable(t1, n);
    printTable(t2, n);
    sort(t1, n);
    sort(t2, n);
    printf("Sorted tables: \n");
    printTable(t1, n);
    printTable(t2, n);
    int length = 0;
    length = one_two(t1, n, t2, n, t3, 2 * n);
    printf("Length of new array: %d\n", length);
    printTable(t3, length);
    return 0;
}