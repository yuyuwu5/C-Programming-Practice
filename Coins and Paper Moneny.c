#include<stdio.h>
int main()
{
    int p, i, j,k,l,m, n,o;
    while(scanf("%d", &p) != EOF){
        int i, j, k, l, m, n, o;
        i = p/1000;
        j = (p - 1000 * i) / 500;
        k = (p - 1000 * i - 500 * j) / 100;
        l = (p - 1000 * i - 500 * j - 100 * k) / 50;
        m = (p - 1000 * i - 500 * j - 100 * k - 50 * l) / 10;
        n = (p - 1000 * i - 500 * j - 100 * k - 50 * l - 10 * m) / 5;
        o = p % 5;
       printf("%d %d %d %d %d %d %d\n", i,j,k,l,m,n,o);
    }
}
