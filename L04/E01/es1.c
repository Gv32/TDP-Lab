#include <stdio.h>

void sottoSequenze(int V[], int N){
    printf ("Dato il vettore ");
    int i,j,conta=0,massimo=0;
    int nsv;
    for(i=0;i<N;i++) {

        if (V[i] != 0) {
            conta++;
        }
        else {
            if (conta > massimo) {
                massimo = conta;
            }
            conta = 0;
        }
    }
    for(i=0;i<N;i++){
        printf("%d ", V[i]);
    }
    nsv=massimo;
    printf(",il/i sottovettore/i di dimensione massima (%d) contenente/i\ndati non nulli sono ", massimo);
    conta = 0;
    for(i=0;i<N;i++){
         if (V[i] != 0) {
            conta++;
        }
        else {
            if (conta == massimo) {
                printf("[");
                for(j=i-conta;j<i;j++){
                    printf("%d ",V[j]);
                }
                printf("] ");
            }
            conta = 0;
        }
    }
}

int main(){
    int N;
    int V[30];
    int i = -1;
    printf("Inserire -1 per finire il caricamento\n");
    do{
        i++;
        printf("Inserire valore %d\n", i+1);
        scanf("%d", &V[i]);
    }while (V[i] != -1);
    N=i;
    sottoSequenze(V, N);
}
