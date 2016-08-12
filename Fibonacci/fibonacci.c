#include <stdio.h>
#include <windows.h>

void nonRecursiveFib(int n);
int recursiveFib(int n);

int main(){
	int n;
	long unsigned int tempoNR, tempoR, inicio, termino;
    long unsigned int result;

	printf("Informe um inteiro a ser calculado: ");
	scanf("%d", &n);

	inicio = GetTickCount();
	nonRecursiveFib(n);
	termino = GetTickCount();

	tempoNR = termino - inicio;

	inicio = GetTickCount();
	result = recursiveFib(n);
	termino = GetTickCount();

	tempoR = termino - inicio;

	printf("Fibonacci rec. de %d = %lu\n", n, result);
    printf("\n");
	printf("Tempo do nao recursivo: %lu ms\n", tempoNR);
	printf("Tempo do recursivo: %lu ms\n", tempoR);

	return 0;
}

void nonRecursiveFib(int n){

	long unsigned int a, b, aux, i;							//Complexidade O(1)

	a = 1;													//Complexidade O(1)
	b = 0;													//Complexidade O(1)

	for(i = 0; i < n; i++){									//Complexidade O(n)
    	aux = a + b;										//Complexidade O(1)
		a = b;												//Complexidade O(1)
		b = aux;											//Complexidade O(1)

		//printf("%d\n", aux);
	}
	printf("\nFibonacci nao rec. de %d = %lu\n", n, aux);	//Complexidade O(1)
}

int recursiveFib(int n){

	if(n == 1 || n == 2)									//Complexidade O(1)
		return 1;                                           //Complexidade O(1)
	else
		return recursiveFib(n - 1) + recursiveFib(n - 2);	//Complexidade O(2^n)
}
