#include <stdio.h>

void coeficientes(int i, int quocientes[]){
    int coefs[2], res;
    coefs[0] = 0, coefs[1] = 1;

    for(int j = i - 1; j >= 0; --j){
        res = (quocientes[j] * coefs[1]) + coefs[0];
        coefs[0] = coefs[1];
        coefs[1] = res;
    }
    if( i % 2 == 0) coefs[0] *= -1;
    else coefs[1] *= -1;
    printf("s: %d   |    t: %d\n", coefs[0], coefs[1]);
}

void mdc(int a, int b, int i, int quocientes[]){
    int resto = 0;
    
    quocientes[i] = a / b;
    resto = a - (quocientes[i] * b);

    if(resto == 0){
        coeficientes(i, quocientes);
    }
    else mdc(b, resto, ++i, quocientes);
}
    
int main(){
    int a, b, quocientes[100];
    printf("Digite a e b [ mdc(a,b) ], para encontrar os coeficientes:\n");
    scanf("%d %d", &a, &b);
    mdc(a, b, 0, quocientes);
}
