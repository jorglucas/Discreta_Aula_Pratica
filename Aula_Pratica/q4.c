#include <stdio.h>
    
void primo();
void funcMmc();
void funcMdc();

int mmc = 1, mdc = 1;

int main(){
    int a, b, max;
    scanf("%d %d", &a, &b);
    if(a > b) max = a;
    else if(b > a) max = b;
    else max = a;

    // Calcular o mmc:
    primo(a, 2, a, b, 0);
    printf("MMC = %d\n", mmc);

    // Calcular o mdc:
    funcMdc(a, b, 2);
    printf("MDC = %d\n", mdc);
}

void primo(int max, int num, int a, int b, int mdcOrMmc){
    if(num <= max){
        int verify = 0;
        for(int i = 2; i < num; i++){
            if(num % i == 0){
                verify = 1;
                break;
            }
        }
        if(verify != 1){
            funcMmc(max, num, a, b);
        }
        else primo(max, ++num, a, b, mdcOrMmc);
    }
    else{
        return;
    }
}

void funcMmc(int max, int num, int a, int b){
    if(a % num == 0 || b % num == 0){
        mmc *= num;
        if(a % num == 0) a /= num;
        if(b % num == 0) b /= num;
        funcMmc(max, num, a, b);
    }
    else primo(max, ++num, a, b, 0);   
}

void funcMdc(int a, int b, int num){
    if(num < 8){
        if(a % num == 0 && b % num == 0){
            mdc *= num;
            funcMdc(a / num, b / num, num);
        }
        else funcMdc(a, b, ++num);
    } 
}