#include <stdio.h>

int mdc();
void coeficientes();
void soluc();
int quocientes[100], i = 0, s, t, k = 1;

int main(){
    int a, b, m, solucoes;
    scanf("%d %d %d", &a, &b, &m);
    printf("Para encontrar a solução de uma congruência do tipo\nax ≡ b mod m, informe a, b e m:\n");
    
    // I. achar o mdc(a, m);
    int res = mdc(a, m);
    // Verificar se o mdc divide b;
        if(b % res == 0){
            // Temos as possíveis soluções (solucoes).
            solucoes = res; 
            while(res != 1){
                i = 0;
                res = mdc(a / res, m / res);
            }
            coeficientes(a, m);
            printf("s = %d\nt = %d\n", s, t);
            // Achar todas as possíveis soluções:
            soluc(b, m, solucoes);


        }


}

int mdc(int a, int m){
    int resto = 0;
    
    quocientes[i] = a / m;
    resto = a - (quocientes[i] * m);

    if(resto == 0){
        printf("mdc = %d\n", m);
        return m;
    }
    else{
        ++i;
        mdc(m, resto);
    }
}

void coeficientes(int a, int m){
    int coefs[2], res;
    coefs[0] = 0, coefs[1] = 1;

    for(int j = i - 1; j >= 0; --j){
        res = (quocientes[j] * coefs[1]) + coefs[0];
        coefs[0] = coefs[1];
        coefs[1] = res;
    }
    if(a > m){
        if(coefs[0] > coefs[1]){
            if( i % 2 == 0) coefs[0] *= -1;
            else coefs[1] *= -1;
            s = coefs[1];
            t = coefs[0];
        } else{
            if( i % 2 == 0) coefs[0] *= -1;
            else coefs[1] *= -1;
            s = coefs[0];
            t = coefs[1];
        }
    }
    else{ // m > a
        if(coefs[0] < coefs[1]){
            if( i % 2 == 0) coefs[0] *= -1;
            else coefs[1] *= -1;
            s = coefs[1];
            t = coefs[0];
        } else{
            if( i % 2 == 0) coefs[0] *= -1;
            else coefs[1] *= -1;
            s = coefs[0];
            t = coefs[1];
        }
    }
}

void soluc(int b, int m, int solucoes){
    int sl[solucoes];
    sl[0] = s * b;
    while(sl[0] > m) sl[0] %= m;

    for(int j = 1; j < solucoes; j++){
        sl[j] = sl[0] + m*k;
        while(sl[j] > m) sl[j] %= m;
        ++k;
    }

    printf("\nSOLUCOES POSSIVEIS: %d\n", solucoes);

    for(int j = 0; j < solucoes; j++){
        printf("S[%d] = %d\n", j + 1, sl[j]);
    }
}