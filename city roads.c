#include<stdio.h>
/*#include "intersection.h"*/
void intersection(int map[100][100], int result[4])
{
    int i, j;
    for(i = 0; i < 4; i++)
        result[i] = 0;
     for(i = 0; i < 100; i++){
      for(j = 0; j < 100; j++){
          if (map[i][j] == 1) {
                if((i != 0) && (i != 99) && (j != 0) && (j != 99)){
                if(map[i+1][j] + map[i-1][j] + map[i][j+1] + map[i][j-1] == 4){
                result[0]++;
                 continue;
                }
                 if (map[i+1][j] + map[i-1][j] + map[i][j+1] + map[i][j-1] == 3){
                    result[1]++;
                  continue;
                }
                 if (map[i+1][j] + map[i][j+1] == 2 ||  map[i-1][j] + map[i][j+1]== 2 || map[i+1][j] + map[i][j-1] == 2 || map[i-1][j] + map[i][j-1] == 2){
                    result[2]++;
                    continue;
                }
                 if (map[i+1][j] + map[i-1][j] + map[i][j+1] + map[i][j-1] == 1){
                    result[3]++;
                    continue;

                }
                }
                else if (i == 0 && j == 0){
                    if(map[i+1][j] + map[i][j+1] == 2)
                        result[2]++;
                    else if (map[i+1][j] + map[i][j+1] == 1)
                        result[3]++;
                }
                 else if (i == 0 && j == 99){
                    if(map[i+1][j] + map[i][j-1] == 2)
                        result[2]++;
                    else if (map[i+1][j] + map[i][j-1] == 1)
                        result[3]++;
                }
                 else if (i == 99 && j == 0){
                    if(map[i-1][j] + map[i][j+1] == 2)
                        result[2]++;
                    else if (map[i-1][j] + map[i][j+1] == 1)
                        result[3]++;
                }
                 else if (i == 99 && j == 99){
                    if(map[i-1][j] + map[i][j-1] == 2)
                        result[2]++;
                    else if (map[i-1][j] + map[i][j-1] == 1)
                        result[3]++;
                }
                 else if (i == 0 && j != 0 && j != 99){
                    if(map[i+1][j] + map[i][j+1] + map[i][j-1] == 3)
                        result[1]++;
                    else if (map[i+1][j] + map[i][j+1] == 2 || map[i+1][j] + map[i][j-1] == 2)
                        result[2]++;
                    else if (map[i+1][j] + map[i][j+1] + map[i][j-1] == 1)
                        result[3]++;
                }
                else if (i == 99 && j != 0 && j != 99){
                    if(map[i-1][j] + map[i][j+1] + map[i][j-1] == 3)
                        result[1]++;
                    else if (map[i-1][j] + map[i][j+1] == 2 || map[i-1][j] + map[i][j-1] == 2)
                        result[2]++;
                    else if (map[i-1][j] + map[i][j+1] + map[i][j-1] == 1)
                        result[3]++;
                }
                else if (j == 0 && i != 0 && i != 99){
                    if(map[i][j+1] + map[i+1][j] + map[i-1][j] == 3)
                        result[1]++;
                    else if (map[i][j+1] + map[i+1][j] == 2 || map[i][j+1] + map[i-1][j] == 2)
                        result[2]++;
                    else if (map[i][j+1] + map[i+1][j] + map[i-1][j] == 1)
                        result[3]++;
                }
                else if (j == 99 && i != 0 && i != 99){
                    if(map[i][j-1] + map[i+1][j] + map[i-1][j] == 3)
                        result[1]++;
                    else if (map[i][j-1] + map[i+1][j] == 2 || map[i][j-1] + map[i-1][j] == 2)
                        result[2]++;
                    else if (map[i][j-1] + map[i+1][j] + map[i-1][j] == 1)
                        result[3]++;
                }
          }
          else
            continue;
      }
     }
     return ;
}
/*

int main(void) {
  int result[4], map[100][100] = {0}, i, j;
     for(i = 0; i < 100; i++)
      for(j = 0; j < 100; j++)
        scanf("%d", &map[i][j]);
    for(i = 0; i < 4; i++)
        result[i] = 0;
     intersection(map, result);

        for(i = 0; i < 4; i++)
        printf("%d\n", result[i]);
}
*/
