#include <stdio.h>

int main(){
    char carattere;
    float op1, op2;
    printf("Inserire il carattere: ");
    carattere = getchar();
    printf("Inserire op1 e op2: ");
    scanf("%f %f", &op1, &op2);
    switch(carattere){
        case '+':
            printf("%c %f", carattere, op1+op2);
            break;
        case '-':
            printf("%c %f", carattere, op1-op2);
            break;
        case '*':
            printf("%c %f", carattere, op1*op2);
            break;
        case '/':
            if(op2 == 0) printf("+inf");
            else printf("%c %f", carattere, op1/op2);
            break;
        default :
            printf("Errore nell'inserimento del carattere");
            break;
    }
}
