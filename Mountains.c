#include<stdio.h>
int main(void)
{
    int n, hnow, hnext, i, sum = 0;
    int flag, use = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &hnext);
        if(i == 0){
            hnow = hnext;
            continue;
        }
        else if(i== 1){
            if(hnext - hnow > 0){
                sum += 3 * (hnext - hnow);
                flag = 0;
            }
            else if(hnext - hnow < 0) {
                sum += 2 * (hnow - hnext);
                flag = 1;
            }
        }
        else{
            if(hnext - hnow > 0){
                if(flag == 0)
                   sum += 4 * (hnext - hnow);
                else
                    sum += 3 * (hnext - hnow);
                flag = 0;
            }
            else {
                if(flag == 0)
                  sum += 3 * (hnow - hnext);
                else
                  sum += 2 * (hnow - hnext);
                flag = 1;
            }
        }
        hnow = hnext;
    }
    printf("%d", sum);
}
