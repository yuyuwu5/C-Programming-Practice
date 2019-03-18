#include<stdio.h>
main()
{
    int a, b, c, k, l;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    k = 2 * a * b + 2 * a * c + 2 * b * c;
    l = a * b * c;
    printf("%d\n", k);
    printf("%d\n", l);
}

