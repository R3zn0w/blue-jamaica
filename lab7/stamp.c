/* Given two arrays T nxn holding integers and P kxl holding values of 0 and 1,
 find biggest value of covering T with P such that every 0 in P is transparent and 1 is non-transparent.

Input:
1 <= n <= 100
1 <= k
l < n
n rows of n integers forming T array
k rows of l {0, 1} forming P array 

Output:
One integer, biggest sum of integers covered with ones

Example:
Input:
5 2 2
5 1 0 1 0
2 3 4 7 1 
2 7 4 0 1
1 8 5 1 9
0 1 6 3 0
0 1
1 0

Output:
12
*/

#include <stdio.h>
#include <stdlib.h>

int stamp(int **arrT, int **arrP, int n, int k, int l, int posY, int posX) //projects stamp from top-left to bot-right
{
    int result = 0;
    if (posY + k - 1 >= n || posX + l - 1 >= n) //if stamp would overflow array just return 0
        return 0;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < l; j++) //loop for every P coordinate
            if (arrP[i][j] == 1)
                result += arrT[i + posY][j + posX]; //if P[i][j] is 1, then add offsetted value T[i+offsetY][j+offsetX] to result

    return result;
}

int main()
{
    int n = 0, k = 0, l = 0, result = 0, temp_res = 0, resY = 0, resX = 0;
    printf("Enter n: \n");
    scanf("%d", &n);
    printf("Enter k and l: \n");
    scanf("%d %d", &k, &l);
    int **arrT = (int **)malloc((unsigned int)n * sizeof(int *)); //allocate memory for array T
    for (int i = 0; i < n; i++)
        arrT[i] = (int *)malloc((unsigned int)n * sizeof(int));   //allocate each row
    int **arrP = (int **)malloc((unsigned int)k * sizeof(int *)); //allocate memory for array P
    for (int i = 0; i < k; i++)
        arrP[i] = (int *)malloc((unsigned int)l * sizeof(int)); //allocate each row
    printf("Enter array T: \n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arrT[i][j]); //fill array T
    printf("Enter array P: \n");
    for (int i = 0; i < k; i++)
        for (int j = 0; j < l; j++)
            scanf("%d", &arrP[i][j]); //fill array P

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            temp_res = stamp(arrT, arrP, n, k, l, i, j);
            if (temp_res > result)
            {
                result = temp_res;
                resY = i;
                resX = j;
            }
        } //driver code for stamp function, loop for every T coordinate

    printf("Biggest sum found was: %d\n", result);
    if (result > 0) //small bonus
    {
        printf("Stamp location: \n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i >= resY && i < resY + k && j >= resX && j < resX + l) //check if actual coordinate matches stamped result
                    printf("\x1b[32m%d \x1b[0m", arrT[i][j]);               //just some ANSI color code, not gonna work everywhere
                else
                    printf("%d ", arrT[i][j]);
            }
            printf("\n");
        }
    }
    for (int i = 0; i < n; i++) //free memory T
        free(arrT[i]);
    free(arrT);
    for (int i = 0; i < k; i++) //free memory P
        free(arrP[i]);
    free(arrP);
    return 0;
}