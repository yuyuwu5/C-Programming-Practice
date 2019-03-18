#include<stdio.h>
int main(void)
{
    int a, b, n, x[65], y[65], p[9] = {0}, i, k = 0, time = 0;
    scanf("%d", &n);
      for(i = 0; i < n; i++){
        scanf("%d%d", &x[i], &y[i]);
        if(x[i] < 3 && y[i] < 3 && x[i] >= 0 && y[i] >= 0)
            {
                if((p[0] == 0) || (p[1] == 0) || (p[2] == 0) || (p[3] == 0) || (p[4] == 0) ||  (p[5] == 0) || (p[6] == 0) ||
                   (p[7] == 0) || (p[8] == 0)){
                if(time % 2 == 0){
                if(x[i] == 0 && y[i] == 0){
                        if(p[0] == 0)
                        p[0] = 1;
                         else{
            time+=2;
            continue;
                }
                }
                if(x[i] == 1 && y[i] == 0){
                    if(p[1] == 0)
                        p[1] = 1;
                         else{
            time+=2;
            continue;
                }
                }
                if(x[i] == 2 && y[i] == 0){
                    if(p[2] == 0)
                        p[2] = 1;
                         else{
            time+=2;
            continue;
                         }
                }
                if(x[i] == 0 && y[i] == 1){
                    if(p[3] == 0)
                        p[3] = 1;
                         else{
            time+=2;
            continue;
                         }
                }
                if(x[i] == 1 && y[i] == 1){
                    if(p[4] == 0)
                        p[4] = 1;
                         else{
            time+=2;
            continue;
                         }
                }
                if(x[i] == 2 && y[i] == 1){
                    if(p[5] == 0)
                        p[5] = 1;
                         else{
            time+=2;
            continue;
                         }
                }
                if(x[i] == 0 && y[i] == 2){
                    if(p[6] == 0)
                        p[6] = 1;
                         else{
            time+=2;
            continue;
                         }
                }
                if(x[i] == 1 && y[i] == 2){
                    if(p[7] == 0)
                        p[7] = 1;
                         else{
            time+=2;
            continue;
                         }
                }
                if(x[i] == 2 && y[i] == 2){
                    if(p[8] == 0)
                        p[8] = 1;
                         else{
            time+=2;
            continue;
                         }
                }

            }
             else if(time % 2 == 1){
                if((p[0] == 0) || (p[1] == 0) || (p[2] == 0) || (p[3] == 0) || (p[4] == 0) ||  (p[5] == 0) || (p[6] == 0) ||
                   (p[7] == 0) || (p[8] == 0)){
                if(x[i] == 0 && y[i] == 0){
                        if(p[0] == 0)
                        p[0] = 2;
                         else{
            time+=2;
            continue;
                         }
                }
                if(x[i] == 1 && y[i] == 0){
                    if(p[1] == 0)
                        p[1] = 2;
                         else{
            time+=2;
            continue;
                         }
                }
                if(x[i] == 2 && y[i] == 0){
                    if(p[2] == 0)
                        p[2] = 2;
                         else{
            time+=2;
            continue;
                         }
                }
                if(x[i] == 0 && y[i] == 1){
                    if(p[3] == 0)
                        p[3] = 2;
                         else{
            time+=2;
            continue;
                         }
                }
                if(x[i] == 1 && y[i] == 1){
                    if(p[4] == 0)
                        p[4] = 2;
                         else{
            time+=2;
            continue;
                         }
                }
                if(x[i] == 2 && y[i] == 1){
                    if(p[5] == 0)
                        p[5] = 2;
                         else{
            time+=2;
            continue;
                         }
                }
                if(x[i] == 0 && y[i] == 2){
                    if(p[6] == 0)
                        p[6] = 2;
                         else{
            time+=2;
            continue;
                         }
                }
                if(x[i] == 1 && y[i] == 2){
                    if(p[7] == 0)
                        p[7] = 2;
                         else{
            time+=2;
            continue;
                         }
                }
                if(x[i] == 2 && y[i] == 2){
                    if(p[8] == 0)
                        p[8] = 2;
                         else{
            time+=2;
            continue;
                         }
                }
         }
             }
                   }
        }
        else{
            time += 2;
            continue;
        }
       if((p[0] == 1 && p[1] == 1 && p[2] == 1) || (p[0] == 1 && p[3] == 1 && p[6] == 1) || (p[0] == 1 && p[4] == 1 && p[8] == 1) ||
          (p[2] == 1 && p[5] == 1 && p[8] == 1) || (p[2] == 1 && p[4] == 1 && p[6] == 1) || (p[3] == 1 && p[4] == 1 && p[5] == 1) ||
          (p[6] == 1 && p[7] == 1 && p[8] == 1) || (p[1] == 1 && p[4] == 1 && p[7] == 1)){
        printf("Black wins.");
        k++;
        break;
       }
    else if((p[0] == 2 && p[1] == 2 && p[2] == 2) || (p[0] == 2 && p[3] == 2 && p[6] == 2) || (p[0] == 2 && p[4] == 2 && p[8] == 2) ||
            (p[2] == 2 && p[5] == 2 && p[8] == 2) || (p[2] == 2 && p[4] == 2 && p[6] == 2) || (p[3] == 2 && p[4] == 2 && p[5] == 2) ||
            (p[6] == 2 && p[7] == 2 && p[8] == 2) || (p[1] == 2 && p[4] == 2 && p[7] == 2)){
        printf("White wins.");
        k++;
        break;
       }
       time++;
    }
    if(k == 0)
        printf("There is a draw.");
        return 0;

}

