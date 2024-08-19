#include <stdio.h>

int main() {
    int total_eleitores, votos_brancos, votos_nulos, votos_validos;
    float percentual_brancos, percentual_nulos, percentual_validos;

    printf("Digite o numero total de eleitores: ");
    scanf("%d", &total_eleitores);

    printf("Digite o numero de votos brancos: ");
    scanf("%d", &votos_brancos);

    printf("Digite o numero de votos nulos: ");
    scanf("%d", &votos_nulos);

    printf("Digite o numero de votos validos: ");
    scanf("%d", &votos_validos);

    percentual_brancos = (votos_brancos / (float)total_eleitores) * 100;
    percentual_nulos = (votos_nulos / (float)total_eleitores) * 100;
    percentual_validos = (votos_validos / (float)total_eleitores) * 100;

    printf("\nPercentual de votos brancos: %.2f%%", percentual_brancos);
    printf("\nPercentual de votos nulos: %.2f%%", percentual_nulos);
    printf("\nPercentual de votos válidos: %.2f%%\n", percentual_validos);

    return 0;
}
