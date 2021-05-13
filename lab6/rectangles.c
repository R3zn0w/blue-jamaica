
/* You are given surface divided by 1x1 squares, each of them being either black or white.
Surface can be covered with rectangle flipping colors of all squares inside

Given list of rectangles with coordinates of opposite corners defined as pairs (x1,y1) and (x2,y2) find sum of black squares after applying all rectangles

Input: 
1 <= N <= 100 000
N rows of
-100 <= x1,y1,x2,y2 <= 100

Output:
One integer - sum of all black rectangles

Example:
Input:
2
-1 -2 1 2
-2 -1 2 1

Output:
8
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 10

void apply_rectangle(bool **arr, int x1, int y1, int x2, int y2) //apply rectangle mask, flipping all bits inside
{
    int sizeX = 0, sizeY = 0, originX = 0, originY = 0;
    sizeX = (x1 > x2) ? x1 - x2 : x2 - x1; //find size of rectangle
    sizeY = (y1 > y2) ? y1 - y2 : y2 - y1;
    originX = (x1 < x2) ? x1 + SIZE / 2 : x2 + SIZE / 2; //determine starting (left-bottom) point of rectangle
    originY = (y1 < y2) ? y1 + SIZE / 2 : y2 + SIZE / 2;
    for (int i = 0; i < sizeY; i++)
        for (int j = 0; j < sizeX; j++)
            arr[originY + i][originX + j] = !arr[originY + i][originX + j]; //flip all bits inside mask
}

int main()
{
    int n = 0, result = 0;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    printf("Enter n: \n");
    scanf("%d", &n);
    bool **arr = (bool **)malloc(SIZE * sizeof(bool *));
    for (int i = 0; i < SIZE; i++)
        arr[i] = (bool *)malloc(SIZE * sizeof(bool *));
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            arr[i][j] = false; //init array as white
    printf("Enter x1, y1, x2, y2: \n");
    for (int i = 0; i < n; i++) //get n lines of input coordinates
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        apply_rectangle(arr, x1, y1, x2, y2);
    }
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            result += (int)arr[i][j]; //count black squares
    printf("Sum of black rectangles is: %d", result);
    for (int i = 0; i < SIZE; i++) //free memory
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}