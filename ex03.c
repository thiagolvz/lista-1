#include <stdio.h>

int main() {
    int anos, meses, dias, totdias;
    printf("Quantos anos, meses e dias voce tem?\n");

    printf("Anos: ");
    scanf("%d", &anos);

    printf("Meses: ");
    scanf("%d", &meses);

    printf("Dias: ");
    scanf ("%d", &dias);

    totdias = (anos * 365) + (meses * 30) + dias;

    printf("Voce tem %d dias de idade.", totdias);

    return 0;
}