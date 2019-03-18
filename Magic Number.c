#include<stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    if(N > 0 && N % 2 == 0){
        if(N > 10000 || N < 1000)
        N = 1;
        else
            N = 0;
    }
    else
        N = 0;
    printf("%d", N);

}
