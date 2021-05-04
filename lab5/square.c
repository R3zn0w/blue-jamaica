
/* Given square array T[n][n] filled with integers and integer k find all squares in array.*/

#include <stdio.h>
#include <stdlib.h>

void find_rectangle(int **arr, int n, int x, int y, int k)
{
    int radius = 1, sum = 0;
    while (x - radius >= 0 && x + radius < n && y - radius >= 0 && y + radius < n) //ensure we are not out of bounds
    {
        sum = 0;
        for (int i = 0; i < (2 * radius + 1); i++) //loop around border
        {
            sum += arr[x - radius + i][y - radius];
            sum += arr[x + radius][y + radius - i];
            sum += arr[x - radius + i][y + radius];
            sum += arr[x - radius][y + radius - i];
        }
        sum -= arr[x - radius][y - radius]; //remove duplicate values
        sum -= arr[x + radius][y - radius];
        sum -= arr[x - radius][y + radius];
        sum -= arr[x + radius][y + radius];
        if (sum == k)
            printf("%d %d\n", x, y);
        radius++;
    }
}

int main()
{
    int n = 0, k = 0;
    unsigned int size = 0;
    printf("Enter n and k: \n");
    scanf("%d %d", &n, &k);
    size = (unsigned int)n;
    int **arr = (int **)malloc(size * sizeof(int *)); //allocate memory for array
    for (int i = 0; i < n; i++)
        arr[i] = (int *)malloc(size * sizeof(int)); //allocate each row

    printf("Enter array line by line (or anyway you like, just separate characters with whitespace): \n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]); //fill up array with input data
    printf("\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            find_rectangle(arr, n, i, j, k);

    for (int i = 0; i < n; i++) //free memory
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}