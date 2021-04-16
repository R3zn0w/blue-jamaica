#include <stdio.h>
#include <stdlib.h>
#include <cmath>

int main()
{

    unsigned int block_size = 128;
    unsigned int current_size = block_size;

    int *arr = (int *)malloc(sizeof(int) * block_size);
    printf("Big factorial calculator\n");
    printf("Enter number: ");

    if (arr != NULL)
    {
        int c = EOF;
        unsigned int i = 0;
        //accept user input until hit enter or end of file
        while ((c = getchar()) != '\n' && c != EOF)
        {
            *(arr + i++) = (int)c - '0';

            //if i reached maximize size then realloc size
            if (i == current_size)
            {
                current_size = current_size + block_size;
                arr = (int *)realloc(arr, current_size);
            }
        }

        printf("value:\n");
        for (int j = 0; j < i; j++)
        {
            printf("%d", *(arr + j));
        }
        //free it
        free(arr);
        arr = NULL;
    }

    return 0;
}