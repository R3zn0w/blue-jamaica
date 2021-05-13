/* Given square array T nxn containing integers find k sequence (lying on row, column or diagonal) such that sum of its values is greatest.
Every element has exactly 8 neighbours, for edge-located elements those will be from the other side of array.
For example T[0][0] will have neighbours T[1][0], T[1][1], T[0][1], T[n-1][1], T[n-1][n-1], T[n-1][0], T[0][n-1], T[1][n-1] 

Input:
First row contains 2 integers
1 <= n <= 100
2 <= k <= n

Output:
Biggest sum of k neighbouring values

Example: 
Input: 
5 2
8 1 0 1 0
2 3 4 7 1
2 7 4 0 1
1 8 5 1 4
0 1 6 3 9

Output:
17
*/

#include <stdio.h>
#include <stdlib.h>

int modulo_Euclidean(int a, int b)
{
    int m = a % b;
    if (m < 0)
        m = (b < 0) ? m - b : m + b; //proper modulo for less than zero numbers
    return m;
}

int check_for_coord(int **arr, int n, int k, int posY, int posX) //check sequences in every direction given origin coordinates posY, posX
{
    int resultColumn = 0, resultRow = 0, resultDiagonal = 0, resultDiagonalRev = 0, result = 0;
    for (int i = 0; i < k; i++)
    {
        resultColumn += arr[modulo_Euclidean(posY + i, n)][posX];                               //check column down from point
        resultRow += arr[posY][modulo_Euclidean(posX + i, n)];                                  //check row to the right
        resultDiagonal += arr[modulo_Euclidean(posY + i, n)][modulo_Euclidean(posX + i, n)];    //check diagonal to the right-bottom
        resultDiagonalRev += arr[modulo_Euclidean(posY + i, n)][modulo_Euclidean(posX - i, n)]; //check the other diagonal (left-bottom)
    }
    result = (resultRow > resultColumn) ? resultRow : resultColumn; //find largest from four results
    result = (resultDiagonal > result) ? resultDiagonal : result;
    result = (resultDiagonalRev > result) ? resultDiagonalRev : result;

    return result;
}

int main()
{
    int n = 0, k = 0, result = 0, temp_res = 0;
    unsigned int size = 0;
    printf("Enter n and k: \n");
    scanf("%d %d", &n, &k);
    size = (unsigned int)n;
    int **arr = (int **)malloc(size * sizeof(int *)); //allocate memory for array
    for (int i = 0; i < n; i++)
        arr[i] = (int *)malloc(size * sizeof(int)); //allocate each row
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]); //fill array
    for (int i = 0; i < n; i++)      //loop for every point in array and check candidates
        for (int j = 0; j < n; j++)
        {
            temp_res = check_for_coord(arr, n, k, i, j);
            result = (temp_res > result) ? temp_res : result;
        }
    printf("Largest sum is: %d", result);
    for (int i = 0; i < n; i++) //free memory
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}