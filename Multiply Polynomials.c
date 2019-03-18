#include<stdio.h>
int main(void)
{
    int n, m, f[100], q[100], p[200] = {0}, i, j, k, l;
    scanf("%d", &n);
    for(i = n-1; i >= 0; i--)
        scanf("%d", &f[i]);
    scanf("%d", &m);
    for(j = m-1; j >= 0; j--)
        scanf("%d", &q[j]);

    for(i = n-1; i >= 0; i--)
     for(j = m-1; j >= 0; j--)
        p[i+j] += f[i] * q[j];


    for(k = n + m -2; k >= 0; k--){
        if(k != 0)
        printf("%d ", p[k]);
        else if(k == 0)
            printf("%d", p[k]);
}

}
