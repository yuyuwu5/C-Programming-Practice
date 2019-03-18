#include<stdio.h>
int main(void)
{
    int n, m, num[10000], mod[10000], max[1000] = {0}, min[1000], sum[1000] = {0}, i, j, k;
    for(k = 0; k < 1000; k++)
        min[k] = 100000;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++){
        scanf("%d", &num[i]);
        mod[i] = num[i] % m;
    }
    for(i = 0; i < n; i++){
     for(j = 0; j < m; j++){
        if((mod[i] == j) ){
            sum[j] += num[i];
            if(max[j] <= num[i])
                max[j] = num [i];
            if(min[j] >= num[i])
                min[j] = num[i];
        }
    }
    }

    for(j = 0; j < m; j++)
        printf("%d %d %d\n", sum[j], max[j], min[j]);

}
