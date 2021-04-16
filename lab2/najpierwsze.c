#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

bool czy_pierwsza(unsigned int n)
{
    if (n <= 3)
        return n > 1;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    unsigned int i = 5;
    while (i * i <= n)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
        i += 6;
    }
    return true;
}

bool czy_niemalejacy(unsigned int n)
{
    while (n)
    {
        if (n % 10 < (n / 10) % 10)
            return false;
        n /= 10;
    }
    return true;
}

int main()
{
    unsigned int liczba = 0;
    printf("Podaj liczbę: \n");
    scanf("%d", &liczba);
    clock_t begin = clock();
    for (unsigned int j = 1; j < liczba; j++)
        if (czy_pierwsza(j))
            if (czy_niemalejacy(j))
                printf("%d \n", j);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Zeszlo %lf sekund.", time_spent);
}