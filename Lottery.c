#include<stdio.h>
int main(void)
{
    int special[3], nor[3], m, j, k, l, o, p, q, r, s, pri = 0, a[3], b[3], c[3], d[3], e[3], f[3], g[3], h[3], i;
    scanf("%d%d%d", &special[0], &special[1], &special[2]);
    scanf("%d%d%d", &nor[0], &nor[1], &nor[2]);
    for(i = 0; i < 3; i++){
    a[i] = nor[i] / 10000000;
    b[i] = nor[i] / 1000000 - 10 * a[i];
    c[i] = nor[i] / 100000 - 10 * b[i] - 100 * a[i];
    d[i] = nor[i] / 10000 - 10 * c[i] - 100 * b[i] - 1000 * a[i];
    e[i] = nor[i] / 1000 - 10 * d[i] - 100 * c[i] - 1000 * b[i] - 10000 * a[i];
    f[i] = nor[i] / 100 - 10 * e[i] - 100 * d[i] - 1000 * c[i] - 10000 * b[i] - 100000 * a[i];
    g[i] = nor[i] / 10 - 10 * f[i] - 100 * e[i] - 1000 * d[i] - 10000 * c[i] - 100000 * b[i] - 1000000 * a[i] ;
    h[i] = nor[i] / 1 - 10 * g[i] - 100 * f[i] - 1000 * e[i] - 10000 * d[i] - 100000 * c[i] -1000000 * b[i] - 10000000 * a[i];
    }
    while (scanf("%d", &m) != EOF){
    for(i = 0; i < 3; i++){
     if (m == special[i]){
        pri += 2000000;
        continue;
    }
    }
    j = m / 10000000;
    k = m / 1000000 - 10 * j;
    l = m / 100000 - 10 * k - 100 * j;
    o = m / 10000 - 10 * l - 100 * k - 1000 * j;
    p = m / 1000 - 10 * o - 100 * l - 1000 * k - 10000 * j;
    q = m / 100 - 10 * p - 100 * o - 1000 * l - 10000 * k - 100000 * j;
    r = m / 10 - 10 * q - 100 * p - 1000 * o - 10000 * l - 100000 * k - 1000000 * j ;
    s = m / 1 - 10 * r - 100 * q - 1000 * p - 10000 * o - 100000 * l -1000000 * k - 10000000 * j;
    for(i = 0; i < 3; i++){
     if((a[i] == j) && (b[i] == k) && (c[i] == l) && (d[i] == o) && (e[i] == p) && (f[i] == q) && (g[i] == r) && (h[i] == s)){
        pri += 200000;
        continue;
     }
     else if((b[i] == k) && (c[i] == l) && (d[i] == o) && (e[i] == p) && (f[i] == q) && (g[i] == r) && (h[i] == s)){
        pri += 40000;
        continue;
     }
     else if((c[i] == l) && (d[i] == o) && (e[i] == p) && (f[i] == q) && (g[i] == r) && (h[i] == s)){
        pri += 10000;
        continue;
     }
     else if((d[i] == o) && (e[i] == p) && (f[i] == q) && (g[i] == r) && (h[i] == s)){
        pri += 4000;
        continue;
     }
     else if((e[i] == p) && (f[i] == q) && (g[i] == r) && (h[i] == s)){
        pri += 1000;
        continue;
     }
     else if((f[i] == q) && (g[i] == r) && (h[i] == s)){
        pri += 200;
     }
    }
    }

    printf("%d\n", pri);
    return 0;
}
