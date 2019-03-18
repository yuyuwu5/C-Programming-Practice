#include<stdio.h>
/*#include"game_of_cell.h"*/
void game_of_cell(int grid[50][50],int outcome[50][50],int N)
{
    int old[50][50], i, j, k, flag = 0;
    for(i = 0; i < 50; i++)
        for(j = 0; j < 50; j++)
        old[i][j] = grid[i][j];
    while(N > 0){
        for(i = 0; i < 50; i++){
         for(j = 0; j < 50; j++){
            if(i + 1 < 50)
                if (old[i+1][j] == 2)
                    flag++;
            if(i-1>= 0)
                if(old[i-1][j] == 2)
                    flag++;
            if(j+1 < 50)
                if(old[i][j+1] == 2)
                    flag++;
            if(j-1 >= 0)
                if(old[i][j-1] == 2)
                    flag++;
            if(i+1 < 50 && j -1 >= 0)
                if(old[i+1][j-1] == 2)
                    flag++;
            if(i-1 >= 0 && j -1 >= 0)
                if(old[i-1][j-1] == 2)
                    flag++;
            if(i+1 < 50 && j +1 < 50)
                if(old[i+1][j+1] == 2)
                    flag++;
            if(i-1 >= 0 && j +1 < 50)
                if(old[i-1][j+1] == 2)
                    flag++;

            if(grid[i][j] == 0){
                if(flag == 3){
                grid[i][j] = 2;
                 flag = 0;
                 continue;
                }
                else{
                    flag = 0;
                 continue;
                }
            }
            else if (grid[i][j] == 1){
                if(flag == 2){
                grid[i][j] = 2;
                 flag = 0;
                 continue;
                }
                 else{
                    flag = 0;
                 continue;
                }
            }
            else if(grid[i][j] == 2){
                if(flag < 2){
                grid[i][j] = 0;
                 flag = 0;
                 continue;
                }
                else if (flag > 3){
                    grid[i][j] = 1;
                     flag = 0;
                     continue;
                }
                 else{
                    flag = 0;
                 continue;
                }
            }
         }
        }
        for(i = 0; i < 50; i++)
          for(j = 0; j < 50; j++)
            old[i][j] = grid[i][j];
        N--;
    }
     for(i = 0; i < 50; i++)
          for(j = 0; j < 50; j++)
            outcome[i][j] = grid[i][j];

}
int main()
{
    int grid[50][50]={0},outcome[50][50]={0},N;
    scanf("%d",&N);
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            scanf("%d",&grid[i][j]);
    game_of_cell(grid,outcome,N);
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            printf("%d%c",outcome[i][j]," \n"[j==49]);
    return 0;
}
