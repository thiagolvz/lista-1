#include <stdio.h>

int main() {
    int num;
    int ant;
    printf("Digite um valor: ");
    scanf("%d", &num);

    ant = (num - 1);
    printf("O antecessor de %d e %d.", num, ant);

    return 0;
}