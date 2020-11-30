#include <stdio.h>

int mdc();
void coeficientes();
int quocientes[100], i = 0, s, t;

int main(){
    int a, b, m;
    scanf("%d %d %d", &a, &b, &m);
    printf("Para encontrar a solução de uma congruência do tipo\nax ≡ b mod m, informe a, b e m:\n");
    
    // I. achar o mdc(a, m);
    int res = mdc(a, m);  
    // Verificar se o mdc divide b;
        if(b % res == 0){ 
            // Temos as possíveis soluções (res).
            while(res != 1){
                a /= res;
                b /= res;
                m /= res;
                i = 0;
                res = mdc(a, m);
            }
            coeficientes(a, m);
            printf("s = %d\nt = %d\n", s, t);


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
