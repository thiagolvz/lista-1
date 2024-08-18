#include <stdio.h>

int main() {
    int salarioFixo, comissaoPorCarro, carrosVendidos;
    float totVendas, valor5porcento, comissaoTotal, salarioFinal;

    printf("Qual o valor do seu salario fixo?\n");
    scanf("%d", &salarioFixo);

    printf("Qual valor voce recebe por cada carro vendido?\n");
    scanf("%d", &comissaoPorCarro);
    
    printf("Quantos carros voce vendeu?\n");
    scanf("%d", &carrosVendidos);

    printf("Qual o valor total de suas vendas?\n");
    scanf("%f", &totVendas);

    comissaoTotal = comissaoPorCarro * carrosVendidos;
    valor5porcento = 0.05 * totVendas;

    salarioFinal = salarioFixo + comissaoTotal + valor5porcento;

    printf("Salario final: R$ %.2f\n", salarioFinal);

    return 0;
}