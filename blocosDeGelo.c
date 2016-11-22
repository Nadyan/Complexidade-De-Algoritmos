#include <stdio.h>
#include <stdlib.h>

/*
 * Nadyan Suriel Pscheidt
 * CAL - Complexidade de Algoritmos
 * Algoritmo Greedy
 * Exercicio URI - 1034
 */


int main(){
    int blocos = 0, i, j = 0, k = 0;
    int *tipos; // vetor com os comprimentos de cada peça
    int qtdRepeticoes, qtdTipos, comprimento;
   
    scanf("%d", &qtdRepeticoes); // Quantidade de cálculos

    for(i = 0; i < qtdRepeticoes; i++){
        scanf("%d %d", &qtdTipos, &comprimento); // Leitura da quantidade de tipos e comprimento
        
        tipos = (int*)malloc(qtdTipos * sizeof(int));  // Alocação do vetor de tipos
        
        for(j = qtdTipos-1; j >= 0; j--){
            scanf("%d", &tipos[j]);  // Leitura dos tipos (comprimento de cada peça)
        }

        while(comprimento != 0){
            if(comprimento < tipos[k]){
                k++;  // se o tipo do vetor for maior do que o comprimento total,
                      // vai para o proximo tipo
            }else{
                blocos += comprimento / tipos[k];  // senao verifica quantos blocos do tamanho k cabem
                comprimento = comprimento % tipos[k];  // calcula o resto para nova interacao
            }
        }
        
        printf("%d\n", blocos);
        
        k = 0; blocos = 0;
        free(tipos);
    }
    
    return 0;
}
