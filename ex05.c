#include <stdio.h> 

int main() {
    int salario, novosalario;
    float decimal, aumento, percentual;

    printf("Qual o salario mensal atual?\n");
    scanf("%d", &salario);

    printf("Qual o percentual de reajuste?\n");
    scanf("%f", &percentual);
    
    decimal = (percentual / 100);
    aumento = (salario * decimal);
    novosalario = (salario + aumento);
    printf("O valor do novo salario e: %d", novosalario);

    return 0;
}