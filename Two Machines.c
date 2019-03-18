#include<stdio.h>
int main(void)
{
    int arrive, atime, btime, aready = 0, bready = 0, wait1 = 0, wait2 = 0, leave, k;
    while(scanf("%d%d%d", &arrive, &atime, &btime) != EOF){
            k = arrive;
        if(arrive < aready){
            wait1 = aready - arrive;
            arrive = aready;
        }
        if(arrive >= aready){
                aready = arrive + atime ;
                arrive += atime;

        }
        if(arrive < bready){
                wait2 = bready - arrive;
                arrive = bready;
            }
        if(arrive >= bready){
                bready = arrive + btime  ;

            }
        leave = wait1 + wait2 + atime + btime + k;
        printf("%d\n", leave);
        wait1 = 0;
        wait2 = 0;

    }
    return 0;
}

