#include <stdio.h>

int main() {
    int mdc();
    int mmc();
    int a, b;
    scanf("%d %d", &a, &b);
    int res = mdc(a, b, 1, 2);
    printf("MDC = %d\n", res);
    res = mmc(a, b, 1, 2);
    printf("MMC = %d\n", res);

}

int mdc(int a, int b, int res, int num){
    
    if(num <= 9){
        if(a == 1 || b == 1) return res;
        else if(a % num == 0 && b % num == 0){
            res *= num;
            mdc(a / num, b / num, res, num);
        }
        else mdc(a, b, res, ++num);
    }
    else return res;
}

int mmc(int a, int b, int res, int num){
    if(num <= 9){
        if(a == 1 && b == 1) return res;
        else if(a % num == 0 || b % num == 0){
            if(a % num == 0) a /= num;  
            if(b % num == 0) b /= num;
            res *= num;
            mmc(a, b, res, num);
        }
        else mmc(a, b, res, ++num);
    }
    else return res;
}