#include <stdio.h>

int main() {
    float n1, n2, n3, mf;

    printf("Digite a nota 1 (N1):\n");
    scanf("%f", &n1);

    printf("Digite a nota 2 (N2):\n");
    scanf("%f", &n2);

    printf("Digite a nota 3 (N3):\n");
    scanf("%f", &n3);

    mf = (2 * n1 + 3 * n2 + 5 * n3) / 10;

    printf("Media final: %.2f\n", mf);

    return 0;
}