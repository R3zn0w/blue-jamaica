#include <stdio.h>
#include <math.h>

void fibo(int n)
{
    unsigned long int fibo[2] = {0, 1};
    unsigned long int helper = 1;
    while (1)
    {
        if (fibo[0] >= sqrt(n))
        {
            printf("Liczba nie jest iloczynem kolejnych elementow ciagu fibonacciego \n");
            return;
        }
        else if (fibo[0] * fibo[1] == n)
        {
            printf("Liczba jest iloczynem %lu oraz %lu \n", fibo[0], fibo[1]);
            return;
        }
        helper = fibo[1];
        fibo[1] = fibo[0] + fibo[1];
        fibo[0] = helper;
    }
}

int main() //2932589879121 = 1346269 * 2178309
{
    unsigned long int liczba = 0;
    printf("Podaj liczbę: \n");
    scanf("%lu", &liczba);
    fibo(liczba);

    return 0;
}