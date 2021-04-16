#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool czy_doskonala(long int n)
{
    long int s = 1, przedzial = sqrt(n);
    for (long int i = 2; i <= przedzial; i++)
        if (n % i == 0)
            s += i + n / i;

    if (n == przedzial * przedzial)
        s -= przedzial;

    if (n == s)
        return 1;

    return 0;
}

int main()
{
    long int gr_dolna, gr_gorna;
    int l_dosk = 0;
    printf("Podaj dolna granice badanego przedzialu: \n");
    scanf("%d", &gr_dolna);
    printf("Podaj gorna granice badanego przedzialu: \n");
    scanf("%d", &gr_gorna);

    for (long int j = gr_dolna; j < gr_gorna; j++)
    {
        if (czy_doskonala(j) == 1)
        {
            printf("%ld ", j);
            l_dosk++;
        }
    }
    printf("Liczba liczb doskonalych: %d", l_dosk);
    return 0;
}