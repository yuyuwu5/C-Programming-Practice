#include<stdio.h>
int main(void)
{
    int n, m, a[200000], i, j, q[200000]={0};
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for(i = 0; i < n; i++)
        q[a[i] % m]++;

    for(j = 0; j < m; j++)
        printf("%d\n", q[j]);
}
