#include<stdio.h>
int main(void)
{
    int n, weight[2048], f[2048] = {0}, sum1, sum2, i, j, k, center;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &weight[i]);


    for(center = 1; center < n-1; center++){
        sum1 = 0;
        sum2 = 0;
        for(i = 0; i < center; i++)
         sum1 += weight[i] * (center - i);
        for(j = center + 1; j < n; j++)
        sum2 += weight[j] * (j - center);
    if(sum1 == sum2)
     break;
    }

    if(sum1 == sum2)
        goto end;

    for(i = 0; i < (n+1)/2 ; i++){
        int temp;
        if(f[i] == 0 && f[n-1-i] == 0){
        temp = weight[i];
        weight[i] = weight[n-1-i];
        weight[n-1-i] = temp;
        f[i] = 1;
        f[n-1-i] = 1;
       for(center = 1; center < n-1; center++){
        sum1 =0; sum2 = 0;
        for(k = 0; k < center; k++)
           sum1 += weight[k] * (center - k);
         for(j = center + 1; j < n; j++)
           sum2 += weight[j] * (j - center);
    if(sum1 == sum2)
     break;
    }
    if(sum1 == sum2)
     break;
        }
    }

 end:
    for(i = 0; i < n; i++){
        if(i != center && i != n-1)
            printf("%d ", weight[i]);
        if(i == n-1)
            printf("%d", weight[i]);
        if(i == center)
            printf("v ");
    }
    return 0;
}
