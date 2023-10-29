#include <stdio.h>

void InsertionSort(int A[], int N) {
    int i, j, l=0, r=N-1, x,contaest=0,containt=0,cint=0;
    for (i = l+1; i <= r; i++) {
        contaest++;
        x = A[i];
        j = i - 1;
        while (j >= l && x < A[j]){
            containt++;
            A[j+1] = A[j];
            j--;
            }
        A[j+1] = x;
        printf("ciclo esterno %d, giri ciclo iterno %d\n",contaest,containt);
        cint=cint + containt;
        containt = 0;
    }
    printf("Scambi totali eseguiti %d\n",cint);
    printf("Iterazioni ciclo esterno %d\n",contaest);
    printf("Iterazioni totali: %d\n\n",cint+contaest);
}

void SelectionSort(int A[], int N) {
    int i, j, l=0, r=N-1, min,contaest=0,containt=0,contasc=0,cint=0;
    int temp;
    for (i = l; i < r; i++) {
        contaest++;
        min = i;
        for (j = i+1; j <= r; j++) {
            if (A[j] < A[min]) min = j;
            containt++;
            }
        if (min != i) {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
            contasc++;
        }
        printf("ciclo esterno %d, giri ciclo iterno %d\n",contaest,containt);
        cint = cint+containt;
        containt=0;
    }
    printf("Scambi totali eseguiti %d\n",contasc);
    printf("Iterazioni ciclo esterno %d\n",contaest);
    printf("Iterazioni totali: %d\n\n",cint+contaest);
}

void ShellSort(int A[], int N) {
    int i, j, x, l=0, r=N-1, h=1,n_iterazioni_e1=0,n_iterazioni_e2=0,n_iterazioni_i=0,n_iterazioni_iTot=0;
    while (h < N/3)
        h = 3*h+1;
    while(h >= 1) {
        n_iterazioni_e1++;
        for (i = l + h; i <= r; i++) {
            n_iterazioni_e2++;
            j = i;
            x = A[i];
            while(j >= l + h && x < A[j-h]) {
                n_iterazioni_i++;
                A[j] = A[j-h];
                j -=h;
            }
            A[j] = x;
            printf("Ciclo esterno numero %d, giri ciclo interno %d\n",n_iterazioni_e2,n_iterazioni_i);
            n_iterazioni_iTot=n_iterazioni_iTot+n_iterazioni_i;
            n_iterazioni_i=0;
        }
        h = h/3;
    }
    printf("Scambi totali eseguiti %d\n",n_iterazioni_iTot);
    printf("Numero di iterazioni del ciclo esterno1 = %d\n",n_iterazioni_e1);
    printf("Numero di iterazioni del ciclo esterno2 = %d\n",n_iterazioni_e2);
    printf("Iterazioni totali %d\n\n",n_iterazioni_iTot+n_iterazioni_e1+n_iterazioni_e2);
}

int main(){
    FILE *fin;
    int n,l,vett1[100],vett2[100],vett3[100];
    if((fin=fopen("sort.txt","r"))==NULL){
        printf("errore di apertura");
        return 1;
    }
    fscanf(fin,"%d\n",&n);
    for(int i=0;i<n;i++){
        fscanf(fin,"%d",&l);
        for(int j=0;j<l;j++){
            fscanf(fin,"%d",&vett1[j]);
            vett2[j]=vett1[j];
            vett3[j]=vett1[j];
        }
        printf("Selection Sort sequenza n %d\n",i+1);
        SelectionSort(vett1,l);
        printf("Insertion Sort sequenza n %d\n",i+1);
        InsertionSort(vett2,l);
        printf("Shell Sort sequenza n %d\n",i+1);
        ShellSort(vett3,l);
    }
}
