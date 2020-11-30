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

    printf("%d\n", coefs[0]);

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
    int a, b, m, quocientes[100];
    scanf("%d %d %d", &a, &b, &m);
    printf("Para encontrar a solução de uma congruência do tipo ax ≡ b mod m, informe a, b e m:\n");
    printf("O inverso de %d (mod %d) = ", a, m);
    mdc(a, m, 0, quocientes);
}
