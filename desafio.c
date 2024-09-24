#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//define o numero maximo de mensagens que podem ser lidas e o maximo de caracteres por mensagem
#define MAX_MESSAGENS 10000
#define MAX_CARACTERES 50

//valores da funcao
#define A0 186.752
#define A1 -148.235
#define A2 34.5049
#define A3 -3.5091
#define A4 0.183166
#define A5 -0.00513554
#define A6 0.0000735464
#define A7 -4.22038e-7

//calculo da funcao
int funcao(int x, int b) {
	double y = A0 + (A1 + b) * x 
           + A2 * pow(x, 2) //pow == funcao da biblioteca math que eleva x a n 
           + A3 * pow(x, 3)
           + A4 * pow(x, 4)
           + A5 * pow(x, 5)
           + A6 * pow(x, 6)
           + A7 * pow(x, 7);
           
           return round(y); 
}

//funcao para decodificar a mensagem
//mensagem_hex == array para decodificar o par de digitos da mensagem
//MAX_CARACTERES * 2 + 1 == 50 * (dois caracteres a serem lidos) + valor de x
void decodificar_mensagem(char mensagem_hex[MAX_CARACTERES * 2 + 1],  int b) {
    int i = 0; //posicao da string 
    int x = 1;  //posicao atual do caracter
    while (mensagem_hex[i] != '\0' && i < MAX_CARACTERES * 2) {
        //leitura dos dois caracteres 
        //hex_caracteres == array de 3 caracteres que armazena os dois digitos da mensagem
        char hex_caracteres[3];
        hex_caracteres[0] = mensagem_hex[i];
        hex_caracteres[1] = mensagem_hex[i + 1];
        hex_caracteres[2] = '\0';
        
        //tabela ascii para a conversao 
        int ascii = (int)strtol(hex_caracteres, NULL, 16);
        
        //00 == encerra a mensagem
        if (ascii == 0) {
            break;
        }
        
        //aplicacao da funcao
        int resultado = funcao(x, b);
        
        //printa o caractere ja decodificado
        if(resultado != 0){
        	printf("%c", ascii);
		}
        
        // incrementa o x e passa para os proximos dois caracteres
        x++;
        i += 2;
    }
    printf("\n");
}

int main() {
    int numeroMensagens, i, b;
    char mensagem_hex[MAX_CARACTERES * 2 + 1];
    
    //le o numero de mensagens a serem decodificadas 
    scanf("%d", &numeroMensagens);
    
    //caso o usu?rio digite 0 para mensagens a serem decodificadas
    if (numeroMensagens < 1 || numeroMensagens > MAX_MESSAGENS) {
        printf("Numero invalido de mensagens.\n");
        return 1;
    }
    
    for (i = 0; i < numeroMensagens; i++) {
        
        //le o valor de b
        scanf("%d", &b);
        
        //le a mensagem em hexadecimal
        scanf("%s", mensagem_hex);

        //print da mensagem decodificada
        decodificar_mensagem(mensagem_hex, b);
    }

    return 0;
}


//fun??o em arquivo separado  
