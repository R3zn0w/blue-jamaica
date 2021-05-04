
/* Given array arr[n][n], where each arr[i][j] is either 0 or 1, find the biggest rectangle consisting of zeroes and print out its size.

Input: 
First row consists of 3 <= n <= 100 
Next n rows containt n digits each, either 0 or 1

Output:
One integer - biggest rectangle area

Example: 
Input:
5
0 1 0 1 0
0 0 0 0 0 
0 0 0 0 1
1 0 0 0 0
0 1 0 0 0 

Output:
9*/

#include <stdio.h>
#include <stdlib.h>

typedef struct coords //structure holding coordinates (was used in previous idea but I kinda liked it and it stayed)
{
    int x;
    int y;
} coords;

/*What we are doing is basically looping through array from top-left to bottom-right and 
checking for biggest rectangle we can draw from current point in bot-right direction.
Knowing that, we need only to check longest route we could take either horizontally or vertically from given point.
When longest route from point arr[i][j] is found we move to arr[i+1][j+1] and start again, until reaching end of loop.
Then shortest of found horizontal and vertical routes are multiplicated to return maximal reactangle size.
T*/

int check_max_fill(int **arr, coords curr_position, int n)
{
    coords start_pos = curr_position;
    coords max_position = {.x = n - 1,
                           .y = n - 1};
    int i = 0,
        j = 0;
    while (curr_position.x <= max_position.x && curr_position.y <= max_position.x)
    {
        for (i = curr_position.y; i <= max_position.y; i++)
            if (arr[curr_position.x][i] == 1)
            {
                max_position.y = i - 1;
                break;
            }
        for (j = curr_position.x; j <= max_position.x; j++)
            if (arr[j][curr_position.y] == 1)
            {
                max_position.x = j - 1;
                break;
            }
        curr_position.x++;
        curr_position.y++;
    }
    return (max_position.y + 1 - start_pos.y) * (max_position.x + 1 - start_pos.x);
}

int main()
{
    int n = 0, max = 0, temp_max = 0;
    unsigned int size = 0;
    coords curr_pos = {0, 0};
    printf("Enter n: \n");
    scanf("%d", &n);
    size = (unsigned int)n;
    int **arr = (int **)malloc(size * sizeof(int *)); //allocate memory for array
    for (int i = 0; i < n; i++)
        arr[i] = (int *)malloc(size * sizeof(int)); //allocate each row
    printf("Enter array line by line (or anyway you like, just separate characters with whitespace): \n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]); //fill up array with input data
    printf("\n");
    for (curr_pos.x = 0; curr_pos.x < n; curr_pos.x++) //driver for function
        for (curr_pos.y = 0; curr_pos.y < n; curr_pos.y++)
        {
            temp_max = check_max_fill(arr, curr_pos, n);
            if (max < temp_max)
                max = temp_max;
        }
    printf("Biggest rectangle found is %d units big", max);
    for (int i = 0; i < n; i++) //free memory
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}