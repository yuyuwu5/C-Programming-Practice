#include<stdio.h>
main()
{
    int n, i, k;
    scanf("%d", &n);
    for(i = 1; i < n; i++)
        printf("%d\n", i);
    for(i = n; i > 0; i--)
        printf("%d\n", i);
}
