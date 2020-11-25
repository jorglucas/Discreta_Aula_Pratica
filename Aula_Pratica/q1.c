#include <stdio.h>

void prime(int n, int c) 
{
    if(n == c) 
    {
      printf("Primo\n");
      return;
    }

    if(n % c == 0)
    {
      printf("Não primo\n");
      return;
    }

    else 
    {
      return (prime(n, c+1));
    }
}

int main()
{
    int num;
    printf("Número: ");
    scanf("%d", &num);
    num <= 1 ? printf("Não\n") : prime(num, 2);
    return 0;
}
