#include <stdio.h>

void primo(int num, int div)
{
    if(num == div)
    {
        printf("%d\n", num);
        return;
    }
    if(num % div == 0)
    {
        printf("%d x ", div);
        return primo(num / div, div);
    }
    else
    {
        return primo(num, ++div);
    }
}

int main()
{
    int num;
    printf("Numero: ");
    scanf("%d", &num);
    primo(num, 2);

    return 0;
}