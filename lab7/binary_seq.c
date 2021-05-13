/* Consider sequences of length N, consisting only of 0 and 1, two '1' elements cannot be neighbours. 
Find K-th sequence in sorted list of sequences of length N.

Input: 
Two non-negative integers
1 <= N <= 63
1 <= K <= 100 000

Output
Found sequence or -1 if K is bigger than number of correct sequences.

Example:
Input: 

3 1

Output:

000
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void increment(int *arr, int n) //increment array representing binary number by one
{
    int shift = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] = (arr[i] + shift) % 2;
        shift = (arr[i] + 1) % 2;
        if (shift == 0)
            return;
    }
}

bool check_sequence(int *arr, int n) //check if sequence is valid (i.e. doesn't contain two ones next to each other)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == 1 && arr[i + 1] == 1)
            return false;
    }
    return true;
}

int main()
{
    int n = 0, k = 0;
    unsigned int size = 0;
    printf("Enter n and k: \n");
    scanf("%d %d", &n, &k);
    size = (unsigned int)n;
    int *arr = (int *)malloc(size * sizeof(int *)); //allocate memory for array
    for (int i = 0; i < n; i++)
        arr[i] = 0; //fill array with zeroes
    int count = 1;
    for (int i = 0; i < (pow(2.0, (double)n) / 2.0) + pow(2.0, (double)n) / 4.0; i++) //loop 2^n-1 + 2^n-2 times, so that increment function doesn't overflow array (flip most significant bit back to 0)
    {
        if (count == k) //check if found k
        {
            for (int j = 0; j < n; j++) //print array
                printf("%d ", arr[j]);
            return 0;
        }
        increment(arr, n);
        if (check_sequence(arr, n))
            count++;
        if (count == k) //check if found k
        {
            for (int j = 0; j < n; j++) //print array
                printf("%d ", arr[j]);
            return 0; //end program on found k-th sequence
        }
    }
    printf("-1");               //print -1 if none found
    for (int i = 0; i < n; i++) //free memory
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}