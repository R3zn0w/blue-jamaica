#include <stdio.h>

int main()
{
    int tab[5] = {0, 1, 2, 3, 4};
    printf("%d ", tab[2]);
    printf("%d ", *(tab + 2));

    return 0;
}