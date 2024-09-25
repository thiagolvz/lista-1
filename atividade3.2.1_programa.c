#include <stdio.h>
#include <limits.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
    int a = CHAR_MAX + 1, b = INT_MAX + 1, c = SHRT_MAX + 1, d = UINT_MAX + 1, f = LONG_MAX + 1, g = ULONG_MAX + 1, h = LLONG_MAX, i = ULLONG_MAX + 1;
	
	printf("Valor após ultrapassar o limite (CHAR_MAX + 1): %d\n", a);
	printf("Valor após ultrapassar o limite (INT_MAX + 1): %d\n", b);
	printf("Valor após ultrapassar o limite (SHRT_MAX + 1): %d\n", c);
	printf("Valor após ultrapassar o limite (UINT_MAX + 1): %d\n", d);
	printf("Valor após ultrapassar o limite (LONG_MAX + 1): %d\n", f);
	printf("Valor após ultrapassar o limite (ULONG_MAX + 1): %d\n", g);
	printf("Valor após ultrapassar o limite (LLONG_MAX + 1): %d\n", h);
	printf("Valor após ultrapassar o limite (ULLONG_MAX + 1): %d\n\n", i);
	
	printf("Este tipo de erro acontece quando se excede a capacidade máxima do tipo ou um ponto mais baixo do segmento de memória, um overflow. Gerando um resultado inesperado.");
    
    return 0;
}

