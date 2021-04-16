#include <stdio.h>

int main()
{

    int x, p;
    float a, netto, brutto, vat;
    printf("Podaj cenę jednostkową towaru: \n");
    scanf("%f", &a);
    printf("Podaj liczbę zakupionych sztuk: \n");
    scanf("%d", &x);
    printf("Podaj stawkę podatku VAT w procentach: \n");
    scanf("%d", &p);
    netto = a * x;
    vat = netto * (p / 100.00);
    brutto = netto + vat;
    printf("Cena netto: %f \n", netto);
    printf("Suma podatku VAT: %f \n", vat);
    printf("SUMA: %f \n", brutto);

    return 0;
}