#include<stdio.h>
main()
{
    int n, m, i = 0, j, k, l, o, p, q, r;
    scanf("%d", &n);
    scanf("%d", &m);
    j = m / 1000000;
    k = m / 100000 - 10 * j;
    l = m / 10000 - 10 * k - 100 * j;
    o = m / 1000 - 10 * l - 100 * k - 1000 * j;
    p = m / 100 - 10 * o - 100 * l - 1000 * k - 10000 * j;
    q = m / 10 - 10 * p - 100 * o - 1000 * l - 10000 * k - 100000 * j;
    r = m / 1 - 10 * q - 100 * p - 1000 * o - 10000 * l - 100000 * k - 1000000 * j ;
    if (10 * j + k == n)
        i++;
    if (10 * k + l == n)
        i++;
    if (10 * l + o == n)
        i++;
    if (10 * o + p == n)
        i++;
    if (10 * p + q == n)
        i++;
    if (10 * q + r == n)
        i++;
    printf("%d\n", i);

}
