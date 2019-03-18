#include<stdio.h>
int main(void)
{
    int n, i, j, k;
    double a[16][16], y[16], x[16];
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%lf", &a[i][j]);
        }
    }
    for(i = 0; i < n; i++)
        scanf("%lf", &y[i]);

    for(i = n-1; i >= 0; i--){
     for(j = n-1; j > i; j--){
        y[i] -= x[j] * a[i][j];
    }
      x[i] = y[i] / a[i][i];
    }
    for(i = 0; i < n; i++)
        printf("%f\n", x[i]);
}

