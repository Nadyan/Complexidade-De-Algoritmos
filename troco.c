#include <stdio.h>

#define MOEDA100 0
#define MOEDA50 1
#define MOEDA25 2
#define MOEDA10 3
#define MOEDA5 4
#define MOEDA1 5

int troco(int valor){
    int quantidadeMoedas = 0;
    int moedas[6] = {100, 50, 25, 10, 5, 1};
    int i, j = 0;
    
    while(valor != 0){
        i = moedas[j];
        
        if(valor < i){
            j++;
        }else{
            quantidadeMoedas += valor / i;   
            
            printf("%d x %d\n", valor/i, moedas[j]);
            
            valor = valor % i;
        }
    }

    return quantidadeMoedas;
}


int main(){
    int valor, resp;
    
    printf("Informe o valor do troco: ");
    scanf("%d", &valor);

    printf("\n\n");
    resp = troco(valor);

    printf("Quantidade minima de notas: %d\n\n", resp);

    return 0;
}
