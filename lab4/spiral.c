
/* Given N, create NxN array filled spirally with incrementing integers

For example 

Input: N = 4

Output:
1 2 3 4
12 13 14 5
11 16 15 6
10 9 8 7 */

#include <stdio.h>
#include <stdlib.h>

void spiral_fill(int n, int **arr)
{
    int row = 0, column = 0, val = 1;
    int av_row = n, av_column = n; //hold remaining available rows and columns
    while (row < av_row && column < av_column)
    {
        /* Print the first row from the remaining
          rows */
        for (int i = column; i < av_column; ++i)
            arr[row][i] = val++;

        row++;

        /* Print the last column from the remaining
          columns */
        for (int i = row; i < av_row; ++i)
            arr[i][av_column - 1] = val++;
        av_column--;

        /* Print the last row from the remaining
           rows */
        if (row < av_row)
        {
            for (int i = av_column - 1; i >= column; --i)
                arr[av_row - 1][i] = val++;
            av_row--;
        }

        /* Print the first column from the remaining
           columns */
        if (column < av_column)
        {
            for (int i = av_row - 1; i >= row; --i)
                arr[i][column] = val++;
            column++;
        }
    }
}
int main()
{
    int n = 0;
    unsigned int size = 0;
    printf("Enter n: \n");
    scanf("%d", &n);
    size = (unsigned int)n;
    int **arr = (int **)malloc(size * sizeof(int *)); //allocate memory for array
    for (int i = 0; i < n; i++)
        arr[i] = (int *)malloc(size * sizeof(int)); //allocate each row

    spiral_fill(n, arr); //fill array

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", arr[i][j]); //print out array
        printf("\n");
    }
    for (int i = 0; i < n; i++) //free memory
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}