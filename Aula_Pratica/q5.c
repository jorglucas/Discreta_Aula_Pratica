#include <stdio.h>
    
int mdc(int a, int b){
    int resto = 0, quociente = 0;
    quociente = a / b;
    resto = a - (quociente * b);
    if(resto == 0) return b;
    else mdc(b, resto);
}
    
int main(){
    int a, b;
    int res;
    printf("Digite os números para encontrar o mdc(a, b):\n");
    scanf("%d %d", &a, &b);
    res = a <= b ? mdc(a, b) : mdc(b, a);  
    printf("MDC(%d,%d) = %d\n", a, b, res);
}