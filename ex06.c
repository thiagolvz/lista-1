#include <stdio.h>

int main() {
    float custo_fabrica, percentual_distribuidor, percentual_impostos, custo_final;

    percentual_distribuidor = 28.0; 
    percentual_impostos = 45.0;     

    printf("Digite o custo de fabrica do carro: R$ ");
    scanf("%f", &custo_fabrica);

    custo_final = custo_fabrica + (custo_fabrica * percentual_distribuidor / 100) + (custo_fabrica * percentual_impostos / 100);

    printf("O custo final ao consumidor e: R$ %.2f\n", custo_final);

    return 0;
}
