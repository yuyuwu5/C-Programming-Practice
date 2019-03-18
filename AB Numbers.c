#include<stdio.h>
main()
{
    int n = 0, m = 0, c, d, e, f, g, h, i, j, y, z;
    scanf("%d", &y);
    scanf("%d", &z);
    c = y / 1000;
    d = y / 100 - 10 * c;
    e = y / 10 - 10 * d - 100 * c;
    f = y - 10 * e - 100 * d - 1000 * c;

    g = z / 1000;
    h = z / 100 - 10 * g;
    i = z / 10 - 10 * h - 100 * g;
    j = z - 10 * i - 100 * h - 1000 * g;

    if (c == g)
        n += 1;
    if (d == h)
        n += 1;
    if (e == i)
        n += 1;
    if (f == j)
        n += 1;
    if ((c == h) || (c == i) || (c == j))
        m += 1;
    if ((d == g) || (d == i) || (d == j))
        m += 1;
    if ((e == g) || (e == h) || (e == j))
        m += 1;
    if ((f == h) || (f == i) || (f == c))
        m += 1;
    printf("%d", n);
    printf("A");
    printf("%d", m);
    printf("B");
}
