#include<stdio.h>

int main(){
    int num1, num2, resto;
    printf("Inserire numero 1: ");
    scanf("%d", &num1);
    printf("Inserire numero 2: ");
    scanf("%d", &num2);
    do{
        if(num1 > num2){
            num1 = num1 % num2;
            if (num1 == 0){
                printf("MCD %d", num2);
            }
        }
        else if(num2 > num1){
            num2 = num2 % num1;
            if (num2==0){
                printf("MCD %d", num1);
            }
        }
    }while(num1 != 0 && num2 != 0);
}
