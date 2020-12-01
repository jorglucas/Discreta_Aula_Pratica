#include <stdio.h>

int mdc();
void coeficientes();
int quocientes[20], i = 0, s, t;

int main(){
    printf("Informe o número de congruências:\n");
    int n;
    scanf("%d", &n);
    int a[n], b[n], m[n + 1];
    m[0] = 1;

    printf("Informe os valores de a e b para as %d congruências, onde:\nx ≡ a (mod b)\n", n);

    for(int j = 0; j < n; j++){
        scanf("%d %d", &a[j], &b[j]);
        m[0] *= b[j]; 
    }

    for(int j = 0; j < n; ++j){
        m[j + 1] = m[0] / (b[j]); 
    }
    
    for(int j = 0; j < n; j++){
        int res = mdc(m[j + 1], b[j]);

        if(res != 1){
            printf("Não há solução!\n");
            continue;
        }
        
        coeficientes(m[j + 1], b[j]);
        i = 0;
        int resto;
        if(s < 0 && b[j] > 0){
            resto = b[j] + s % b[j];
        } else resto = s % b[j];
        
        printf("S%d = %d\n", j + 1, resto);
    }

}

int mdc(int a, int m){
    int resto = 0;
    
    quocientes[i] = a / m;
    resto = a - (quocientes[i] * m);

    if(resto == 0){
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