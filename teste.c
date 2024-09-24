#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//define o n?mero m?ximo de mensagens que podem ser lidas e o m?ximo de caracteres por mensagem
#define MAX_MESSAGENS 10000
#define MAX_CARACTERES 50

//valores da fun??o
#define A0 186.752
#define A1 -148.235
#define A2 34.5049
#define A3 -3.5091
#define A4 0.183166
#define A5 -0.00513554
#define A6 0.0000735464
#define A7 -4.22038e-7

//calculo da funçao
int funcao(int x, int b) {
	double y = A0 + (A1 + b) * x 
           + A2 * pow(x, 2) //pow == funçao da biblioteca math que eleva x a n 
           + A3 * pow(x, 3)
           + A4 * pow(x, 4)
           + A5 * pow(x, 5)
           + A6 * pow(x, 6)
           + A7 * pow(x, 7);
           
           return round(y); 
}

//funçao para decodificar a mensagem
//mensagem_hex == array para decodificar o par de digitos da mensagem
//MAX_CARACTERES * 2 + 1 == 50 * (dois caracteres a serem lidos) + valor de x
void decodificar_mensagem(char mensagem_hex[MAX_CARACTERES * 2 + 1],  int b) {
    int i = 0; //posi??o da string 
    int x = 1;  //posi??o atual do caracter
    while (mensagem_hex[i] != '\0' && i < MAX_CARACTERES * 2) {
        //leitura dos dois caracteres 
        //hex_caracteres == array de 3 caracteres que armazena os dois d?gitos da mensagem
        char hex_caracteres[3];
        hex_caracteres[0] = mensagem_hex[i];
        hex_caracteres[1] = mensagem_hex[i + 1];
        hex_caracteres[2] = '\0';
        
        //tabela ascii para a convers?o 
        int ascii = (int)strtol(hex_caracteres, NULL, 16);
        
        //00 == encerra a mensagem
        if (ascii == 0) {
            break;
        }
        
        //aplica??o da fun??o
        int resultado = funcao(x, b);
        
        //printa o caractere j? decodificado
        if(resultado != 0){
        	printf("%c", ascii);
		}
        
        // incrementa o x e passa para os pr?ximos dois caracteres
        x++;
        i += 2;
    }
    printf("\n");
}

int main() {
    int n, i, b;
    char mensagem_hex[MAX_CARACTERES * 2 + 1];
    
    //le o n?mero de mensagens a serem decodificadas 
    printf("Digite o n?mero de mensagens a serem decodificadas (1 a 10000): ");
    scanf("%d", &n);
    
    //caso o usu?rio digite 0 para mensagens a serem decodificadas
    if (n < 1 || n > MAX_MESSAGENS) {
        printf("N?mero inv?lido de mensagens.\n");
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        
        //le a mensagem em hexadecimal
        printf("Digite a mensagem %d em hexadecimal: ", i + 1);
        scanf("%s", mensagem_hex);
        
        //le o valor de b
        printf("Digite o valor de b (-100 a 100): ");
        scanf("%d", &b);

        //print da mensagem decodificada 
        printf("Mensagem decodificada: ");
        decodificar_mensagem(mensagem_hex, b);
    }

    return 0;
}


//função em arquivo separado  
//trocar as ordens de leitura, quantas mensagens a serem lidas, b, mensagem
//tirar os printf e mensagem decodificada
