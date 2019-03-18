#include<stdio.h>
int selection(int n,int m)
{
   int i, j, k, a[15], sum = 0, p, q;
   if(m == 0)
    return 1;
   else{
    for(j = 0; j <= m; j++){
    for(k = 0; k < j; k++)
        p *= (n-k) ;
    for(k = 1; k <= j;k++)
        q *= k ;
    a[j] = p / q ;
    p = 1;
    q = 1;
    }
    for(j = 0; j <= m; j++)
        sum += a[j];
    return sum;
}
}
int main(void)
{
    int n, m, sum = 0;
    scanf("%d%d", &n, &m);
    sum = selection(n, m);
    printf("%d\n", sum);
    return 0;


}
