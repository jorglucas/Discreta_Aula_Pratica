#include <stdio.h>

void coeficientes(int i, int quociente[]){
    int cs[i - 1], cont[2];
    cont[0] = 0, cont[1] = 1;
    for(int j = 0; j < i; i++){
        cs[j] = (quociente[j] * cont[1]) + cont[0];
        cont[0] = cont[1];
        cont[1] = cs[j];
    }
    printf("%d %d\n", cont[i - 3], cont[i - 2]);
}

void mdc(int a, int b, int i){
    int resto = 0, quociente[100];
    quociente[i] = a / b;
    resto = a - (quociente[i] * b);
    if(resto == 0){
        if(b != 1) printf("A e B não são coprimos.\n");
        else{
            coeficientes(i, quociente);
        } 
    }
    else mdc(b, resto, ++i);
}
    
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    mdc(a, b, 0);
}