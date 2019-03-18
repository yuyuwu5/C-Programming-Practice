#include<stdio.h>
int main(void)
{
    int n,left[20][20], right[20][20], sum[20][20] = {0}, i, j, k;
    scanf("%d", &n);
    for(j = 0; j < n; j++)
     for(i = 0; i <= j; i++){
        scanf("%d%d", &left[j][i], &right[j][i]);
        sum[j][i] = left[j][i] + right[j][i];
        int h, v;
        h = left[j][i];
        v = sum[j][i];
        if(h != 0){
        while(v % h != 0){
            int temp;
            temp = v % h;
            v = h;
            h = temp;
        }
        left[j][i] /= h;
        sum[j][i] /= h;
        right[j][i] = sum[j][i] - left[j][i];
        }

     }
    long long dotup[20][20] = {0} , dotdown[20][20] = {0}, temp1up, temp1down,temp2up, temp2down;
    dotup[0][0] = 1;
    dotdown[0][0] = 1;
    for(j = 1; j <= n; j++)
     for(i = 0; i <= j; i++){
        if(dotup[j-1][i] != 0){
        temp1up = dotup[j-1][i] * left[j-1][i];
        temp1down = dotdown[j-1][i] * sum[j-1][i];
        }
        else{
             temp1up= 0;
             temp1down = 1;
        }
        if(i-1 >= 0){
        temp2up = dotup[j-1][i-1] * right[j-1][i-1];
        temp2down = dotdown[j-1][i-1] * sum[j-1][i-1];
        }
        else{
             temp2up= 0;
             temp2down = 1;
        }
        dotdown[j][i] = temp1down * temp2down;
        dotup[j][i] = temp1up * temp2down + temp2up * temp1down;
    long long r,f;
     r = dotup[j][i];
     f = dotdown[j][i];
     if(r != 0){
    while(f % r != 0){
        long long temp;
        temp = f % r;
        f = r;
        r = temp;
    }
        dotup[j][i] /= r;
        dotdown[j][i] /= r;
     }
     else
        dotdown[j][i] = 1;
     }
     for(i = 0; i <= n; i++)
        printf("%lld/%lld\n", dotup[n][i], dotdown[n][i]);
}
