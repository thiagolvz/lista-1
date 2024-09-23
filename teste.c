#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

//define o número máximo de mensagens que podem ser lidas e o máximo de caracteres por mensagem
#define MAX_MESSAGENS 10000
#define MAX_CARACTERES 50

//valores da função
#define A0 186.752
#define A1 -148.235
#define A2 34.5049
#define A3 -3.5091
#define A4 0.183166
#define A5 -0.00513554
#define A6 0.0000735464
#define A7 -4.22038e-7

//calculo da função
double funcao(int x, int b) {
    return A0 + (A1 + b) * x 
           + A2 * pow(x, 2) //pow == função da biblioteca math que eleva x a n 
           + A3 * pow(x, 3)
           + A4 * pow(x, 4)
           + A5 * pow(x, 5)
           + A6 * pow(x, 6)
           + A7 * pow(x, 7);
}

//função para decodificar a mensagem
//mensagem_hex == array para decodificar o par de digitos da mensagem
//MAX_CARACTERES * 2 + 1 == 50 * (dois caracteres a serem lidos) + valor de x
void decodificar_mensagem(char mensagem_hex[MAX_CARACTERES * 2 + 1],  int b) {
    int i = 0; //posição da string 
    int x = 1;  //posição atual do caracter
    while (mensagem_hex[i] != '\0' && i < MAX_CARACTERES * 2) {
        //leitura dos dois caracteres 
        //hex_caracteres == array de 3 caracteres que armazena os dois dígitos da mensagem
        char hex_caracteres[3];
        hex_caracteres[0] = mensagem_hex[i];
        hex_caracteres[1] = mensagem_hex[i + 1];
        hex_caracteres[2] = '\0';
        
        //tabela ascii para a conversão 
        int ascii = (int)strtol(hex_caracteres, NULL, 16);
        
        //00 == encerra a mensagem
        if (ascii == 0) {
            break;
        }
        
        //aplicação da função
        double resultado = funcao(x, b);
        
        //printa o caractere já decodificado
        printf("%c", ascii);
        
        // incrementa o x e passa para os próximos dois caracteres
        x++;
        i += 2;
    }
    printf("\n");
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    int n, i, b;
    char mensagem_hex[MAX_CARACTERES * 2 + 1];
    
    //le o número de mensagens a serem decodificadas 
    printf("Digite o número de mensagens a serem decodificadas (1 a 10000): ");
    scanf("%d", &n);
    
    //caso o usuário digite 0 para mensagens a serem decodificadas
    if (n < 1 || n > MAX_MESSAGENS) {
        printf("Número inválido de mensagens.\n");
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        
        //le a mensagem em hexadecimal
        printf("Digite a mensagem %d em hexadecimal: ", i + 1);
        scanf("%s", mensagem_hex);
        
        //le o valor de b
        printf("Digite o valor de b (-100 a 100): ");
        scanf("%d", &b);
        
        //casp b seja menor que -100 ou maior que 100
        if (b < -100 || b > 100) {
            printf("Valor de b inválido.\n");
            return 1;
        }
        
        //print da mensagem decodificada 
        printf("Mensagem decodificada: ");
        decodificar_mensagem(mensagem_hex, b);
    }

    return 0;
}

