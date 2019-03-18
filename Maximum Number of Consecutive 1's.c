#include<stdio.h>
int main()
{
    int max = 0, conti = 0;
    long long k = 0;
    while(scanf("%lld", &k) != EOF){
        for(int i = 0; i < 31; i++){
            if(k % 2 == 1){
                conti++;
                if(max < conti)
                    max = conti;
            }
            else
                conti = 0;
            if(k / 2 == 0)
                break;
            else
                k /= 2;
        }
     printf("%d\n", max);
     max = 0;
     conti = 0;
    }
}
