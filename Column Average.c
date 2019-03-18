#include<stdio.h>
main()
{
    int R, C, r[100][100], i, k, aver[100] = {0}, sum[100] = {0};
    scanf("%d%d", &R, &C);
    for(i = 0; i < R; i++)
     for(k = 0; k < C; k++){
        scanf("%d", &r[i][k]);
    }
    for(k = 0; k < C; k++)
     for(i = 0; i < R; i++){
         sum[k] += r[i][k];
    }
    for(k = 0; k < C; k++){
        aver[k] = sum[k] / R;
        printf("%d\n", aver[k]);
    }
}
