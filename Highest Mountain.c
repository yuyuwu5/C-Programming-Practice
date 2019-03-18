#include<stdio.h>
int main(void)
{
    int n, m, num, s, k, ss, kk, c;
    int max = -1000000, second = -1000000;
    int allmax = -1000000, sss, kkk;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
     for(int j = 1; j <= m; j++){
        scanf("%d", &num);
        if(max <= num){
          if(second <= max){
            second = max;
            ss = s;
            kk = k;
        }
           max = num;
            s = i;
            k = j;
        }
        else if(second <= num){
            second = num;
            ss = i;
            kk = j;
        }
    }
    if(allmax <= max){
        allmax = max;
        sss = s;
        kkk = k;
    }
   printf("%d %d\n", k, kk);
    max = -1000000;
    second = -1000000;
    }
   printf("%d %d\n", sss, kkk);
}
