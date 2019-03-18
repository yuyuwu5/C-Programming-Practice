#include<stdio.h>
main()
{
    int n, i, k;
    scanf("%d", &n);
    for(i = 1; i <= n;  i++)
        for(k = 1; k <= i; k++)
        printf("%d", k);
}
