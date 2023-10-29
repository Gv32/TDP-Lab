#include <stdio.h>

int main(){
    FILE *file1,*file2;
    float op1,op2;
    char carattere;
    if((file1 = fopen("Operations.txt", "r"))==NULL){
        printf("Errore apertura file\n");
        return 0;
    }
    if((file2 = fopen("Results.txt", "w"))==NULL){
        printf("Errore apertura file\n");
        return 1;
    }
    while(!feof(file1)){
        fscanf(file1, "%c %f %f\n",&carattere, &op1, &op2);
        switch(carattere){
        case '+':
            fprintf(file2,"%c %.2f\n", carattere, op1+op2);
            break;
        case '-':
            fprintf(file2,"%c %.2f\n", carattere, op1-op2);
            break;
        case '*':
            fprintf(file2,"%c %.2f\n", carattere, op1*op2);
            break;
        case '/':
            if(op2 == 0) fprintf(file2,"+inf\n");
            else fprintf(file2,"%c %.2f\n", carattere, op1/op2);
            break;
        default :
            printf("Errore di input");
        }
    }
    fclose(file1);
    fclose(file2);
}
