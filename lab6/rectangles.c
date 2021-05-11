
/**/

#include <stdio.h>

int main()
{
    int n = 0;
    printf("Enter n: \n");
    scanf("%d", &n);
    int arr[200][200] = {0};
    printf("Enter array line by line (or anyway you like, just separate characters with whitespace): \n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]); //fill up array with input data
    printf("\n");
    return 0;
}