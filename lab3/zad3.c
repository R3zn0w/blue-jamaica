#include <stdio.h>

void printTable(int arr[], int n, int k, int forward) // forward = 1 for forward, -1 for backward
{
    int i = k;
    do
    {
        printf(" %d ", arr[i]);
        if (i + forward == -1)
            i = i + n - 1;
        else
            i = (i + forward) % n;
    } while (i != k);
}

int main()
{
    int t[10] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2};
    printTable(t, 10, 2, 1);

    return 0;
}