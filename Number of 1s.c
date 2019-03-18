#include<stdio.h>
int main()
{
    int num = 0;
    long long k = 0;
    while(scanf("%lld", &k) != EOF){
        for(int i = 0; i < 31; i++){
            if(k % 2 == 1)
                num++;
            if(k / 2 == 0)
                break;
            else
                k /= 2;
        }
     printf("%d\n", num);
     num = 0;
    }
}
