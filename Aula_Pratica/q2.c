#include <time.h>
#include <stdio.h>
#include <stdlib.h>

static clock_t startTime = 0;
int count;

void tempo()
{
    clock_t toc = clock();
    if(((double)(toc - startTime) / CLOCKS_PER_SEC) >= 60.0)
    {
        printf("%d números gerados\n", count);
        exit(1);
    }
    return;
}
void primo(int i, int div)
{
    tempo();
    if(i == div)
    {
        printf("%d\n", i);
        ++count;
        return;
    }
    if(i % div == 0)
    {
        return;
    }
    else
    {
        primo(i, ++div);
    }
    return;
}

int main()
{
    printf("2\n");
    int i = 2;
    while(1)
    {
        primo(++i, 2);
    }

    return 0;
}