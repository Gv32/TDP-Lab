#include <stdio.h>
#define filein "numeri.txt"

int main() {
    FILE *fin;
    int num,x0,x1,x2,massimo = 0,minimo = 20,scartati=0;
    int flag = 0;
    if ((fin=fopen(filein,"r"))==NULL){
        printf("errore di apertura");
        return 1;
    }
    fscanf(fin,"%d",&x0);
    fscanf(fin,"%d",&x1);
    if(x0>massimo){
        massimo=x0;
    }
    if(x0<minimo){
        minimo=x0;
    }
    if(x1>massimo){
        massimo=x1;
    }
    if(x1<minimo){
        minimo=x1;
    }
    while(fscanf(fin,"%d",&x2)!=EOF){
        if (x0 + x1 == x2 || x0 - x1 == x2 || x1 - x0 == x2 || x1 * x0 == x2 || (x0 / x1 == x2)&& x1 != 0){
            flag = 1;
        }
        if(x2>massimo){
            massimo=x2;
        }
        if(x2<minimo){
            minimo=x2;
        }
        if (flag == 1){
            x0 = x1;
            x1 = x2;
            flag = 0;
        }else{
            scartati++;
        }
    }
    printf("Numero massimo: %d\n",massimo);
    printf("Numero minimo: %d\n",minimo);
    printf("Numeri scartati: %d",scartati);
}
