#include<stdio.h>
int main(void)
{
    int n, intersection = 0, junction = 0, turn = 0 ,end = 0, road[100][100], i, j, k;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
     for(j = 0; j < n; j++)
        scanf("%d", &road[i][j]);
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
          if(road[i][j] == 1){
              if(i != 0 && j != 0 && i != n-1 && j != n-1){
            if(road[i+1][j] == 1 && road[i][j+1] == 1 && road[i-1][j] == 1 && road[i][j-1] == 1){
                intersection++;
                continue;
            }
            if(road[i+1][j] == 0 && road[i][j+1] == 1 && road[i-1][j] == 1 && road[i][j-1] == 1){
               junction++;
                continue;
            }
             if(road[i+1][j] == 1 && road[i][j+1] == 0 && road[i-1][j] == 1 && road[i][j-1] == 1){
               junction++;
                continue;
            }
             if(road[i+1][j] == 1 && road[i][j+1] == 1 && road[i-1][j] == 0 && road[i][j-1] == 1){
               junction++;
                continue;
            }
             if(road[i+1][j] == 1 && road[i][j+1] == 1 && road[i-1][j] == 1 && road[i][j-1] == 0){
               junction++;
                continue;
            }
             if(road[i+1][j] == 0 && road[i][j+1] == 0 && road[i-1][j] == 1 && road[i][j-1] == 1){
               turn++;
                continue;
            }

            if(road[i+1][j] == 1 && road[i][j+1] == 0 && road[i-1][j] == 0 && road[i][j-1] == 1){
               turn++;
                continue;
            }

            if(road[i+1][j] == 1 && road[i][j+1] == 1 && road[i-1][j] == 0 && road[i][j-1] == 0){
               turn++;
                continue;
            }
            if(road[i+1][j] == 0 && road[i][j+1] == 1 && road[i-1][j] == 1 && road[i][j-1] == 0){
               turn++;
                continue;
            }

            if(road[i+1][j] == 1 && road[i][j+1] == 0 && road[i-1][j] == 0 && road[i][j-1] == 0){
               end++;
                continue;
            }
             if(road[i+1][j] == 0 && road[i][j+1] == 1 && road[i-1][j] == 0 && road[i][j-1] == 0){
               end++;
                continue;
            }
             if(road[i+1][j] == 0 && road[i][j+1] == 0 && road[i-1][j] == 1 && road[i][j-1] == 0){
               end++;
                continue;
            }
             if(road[i+1][j] == 0 && road[i][j+1] == 0 && road[i-1][j] == 0 && road[i][j-1] == 1){
               end++;
                continue;
            }
           }
           if (i == 0 && j == 0){
           if(road[i+1][j] == 1 && road[i][j+1] == 1){
            turn++;
            continue;
           }
           else if((road[i+1][j] == 1 && road[i][j+1] == 0) || (road[i+1][j] == 0 && road[i][j+1] == 1)  ){
            end++;
            continue;
           }
           }
           if (i == 0 && j == n-1){
           if(road[i+1][j] == 1 && road[i][j-1] == 1){
            turn++;
            continue;
           }
           if((road[i+1][j] == 1 && road[i][j-1] == 0) || (road[i+1][j] == 0 && road[i][j-1] == 1)){
            end++;
            continue;
           }
           }
           if (i == n-1 && j == 0){
           if(road[i-1][j] == 1 && road[i][j+1] == 1){
            turn++;
            continue;
           }
           if((road[i-1][j] == 1 && road[i][j+1] == 0) ||(road[i-1][j] == 0 && road[i][j+1] == 1)){
            end++;
            continue;
           }
           }
           if (i == n-1 && j == n-1){
           if(road[i-1][j] == 1 && road[i][j-1] == 1){
            turn++;
            continue;
           }
           if((road[i-1][j] == 1 && road[i][j-1] == 0) || (road[i-1][j] == 0 && road[i][j-1] == 1)){
            end++;
            continue;
           }
           }
           if (i == 0 && j != 0 && j != n-1){
            if(road[i+1][j] == 1 && road[i][j+1] == 1 && road[i][j-1] == 1){
                junction++;
                continue;
            }
            if(road[i+1][j] == 1 && road[i][j+1] == 1 && road[i][j-1] == 0){
                turn++;
                continue;
            }
            if(road[i+1][j] == 1 && road[i][j+1] == 0 && road[i][j-1] == 1){
                turn++;
                continue;
            }
            if(road[i+1][j] == 1 && road[i][j+1] == 0 && road[i][j-1] == 0){
                end++;
                continue;
            }
             if(road[i+1][j] == 0 && road[i][j+1] == 1 && road[i][j-1] == 0){
                end++;
                continue;
            }
             if(road[i+1][j] == 0 && road[i][j+1] == 0 && road[i][j-1] == 1){
                end++;
                continue;
            }
           }
            if (i == n-1 && j != 0 && j != n-1){
            if(road[i-1][j] == 1 && road[i][j+1] == 1 && road[i][j-1] == 1){
                junction++;
                continue;
            }
            if(road[i-1][j] == 1 && road[i][j+1] == 1 && road[i][j-1] == 0){
                turn++;
                continue;
            }
            if(road[i-1][j] == 1 && road[i][j+1] == 0 && road[i][j-1] == 1){
                turn++;
                continue;
            }
            if(road[i-1][j] == 1 && road[i][j+1] == 0 && road[i][j-1] == 0){
                end++;
                continue;
            }
             if(road[i-1][j] == 0 && road[i][j+1] == 1 && road[i][j-1] == 0){
                end++;
                continue;
            }
             if(road[i-1][j] == 0 && road[i][j+1] == 0 && road[i][j-1] == 1){
                end++;
                continue;
            }
           }
            if (j == 0 && i != 0 && i != n-1){
            if(road[i][j+1] == 1 && road[i+1][j] == 1 && road[i-1][j] == 1){
                junction++;
                continue;
            }
            if(road[i][j+1] == 1 && road[i+1][j] == 1 && road[i-1][j] == 0){
                turn++;
                continue;
            }
            if(road[i][j+1] == 1 && road[i+1][j] == 0 && road[i-1][j] == 1){
                turn++;
                continue;
            }

            if(road[i][j+1] == 1 && road[i+1][j] == 0 && road[i-1][j] == 0){
                end++;
                continue;
            }
             if(road[i][j+1] == 0 && road[i+1][j] == 1 && road[i-1][j] == 0){
                end++;
                continue;
            }
             if(road[i][j+1] == 0 && road[i+1][j] == 0 && road[i-1][j] == 1){
                end++;
                continue;
            }
           }
            if (j == n-1 && i != 0 && i != n-1){
            if(road[i][j-1] == 1 && road[i+1][j] == 1 && road[i-1][j] == 1){
                junction++;
                continue;
            }
            if(road[i][j-1] == 1 && road[i+1][j] == 1 && road[i-1][j] == 0){
                turn++;
                continue;
            }
            if(road[i][j-1] == 1 && road[i+1][j] == 0 && road[i-1][j] == 1){
                turn++;
                continue;
            }

            if(road[i][j-1] == 1 && road[i+1][j] == 0 && road[i-1][j] == 0){
                end++;
                continue;
            }
             if(road[i][j-1] == 0 && road[i+1][j] == 1 && road[i-1][j] == 0){
                end++;
                continue;
            }
             if(road[i][j-1] == 0 && road[i+1][j] == 0 && road[i-1][j] == 1){
                end++;
                continue;
            }
           }
}
      }
}
printf("%d\n", intersection);
printf("%d\n", junction);
printf("%d\n", turn);
printf("%d\n", end);
return 0;
}
