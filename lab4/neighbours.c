
/* Given array F[n][n] filled with 0 or 1 calculate array W[n][n] such that W[i][j] is sum of elements F[i'][j'] with distance from F[i][j] being less or equal r.
Distance is defined as d(F[i][j],F[i'][j']) = max(|i-i'|,|j-j'|)

Inputs:
First row will contain two positive integers 2 <= n <= 100 and r < n
Next n rows will contain n either ones or zeros.

Example:
3 1
1 0 1
1 1 1
0 0 1

Correct answer is:
3 5 3
3 6 4
2 4 3
*/

#include <stdlib.h>
#include <stdio.h>

int sum_neighbours(int row, int column, int distance, int **arr, int n)
{
    int sum = 0;
    for (int i = row - distance; i <= row + distance; i++) //start from left upper corner and go all the way down to right lower corner
    {
        if (i < 0 || i >= n)
            continue;
        for (int j = column - distance; j <= column + distance; j++)
        {
            if (j < 0 || j >= n)
                continue;
            sum += arr[i][j];
        }
    }
    return sum;
}

int main()
{
    int n = 0, r = 0;
    unsigned int size = 0;
    printf("Enter n and r: \n");
    scanf("%d %d", &n, &r);
    size = (unsigned int)n;
    int **arr = (int **)malloc(size * sizeof(int *)); //allocate memory for array F
    for (int i = 0; i < n; i++)
        arr[i] = (int *)malloc(size * sizeof(int)); //allocate each row

    int **arrW = (int **)malloc(size * sizeof(int *)); //allocate memory for array W
    for (int i = 0; i < n; i++)
        arrW[i] = (int *)malloc(size * sizeof(int)); //allocate each row
    printf("Enter array line by line (or anyway you like, just separate characters with whitespace): \n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]); //fill up array F with input data
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            arrW[i][j] = sum_neighbours(i, j, r, arr, n); //calculate array W one indice at a time
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", arrW[i][j]); //print out W array
        printf("\n");
    }
    for (int i = 0; i < n; i++) //free memory
    {
        free(arr[i]);
        free(arrW[i]);
    }
    free(arr);
    free(arrW);
    return 0;
}