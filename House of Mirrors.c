#include<stdio.h>
int main(void)
{
    int d, w, i, j, map[100][100] = {{0}}, point[400][2], q[400][2];
    scanf("%d%d", &w, &d);
    for(i = 1; i < d+1; i++)
     for(j = 1; j < w+1; j++)
        scanf("%d", &map[i][j]);

    int k = 0;
        for(j = 1; j < w + 1; j++){
            point[k][0] = d+1;
            point[k][1] = j;
            q[k][0] = point[k][0];
            q[k][1] = point[k][1];
            k++;
        }
        for(i = d; i > 0; i--){
            point[k][0] = i;
            point[k][1] = w+1;
            q[k][0] = point[k][0];
            q[k][1] = point[k][1];
            k++;
        }
      for(j = w; j > 0; j--){
            point[k][0] = 0;
            point[k][1] = j;
            q[k][0] = point[k][0];
            q[k][1] = point[k][1];
            k++;
    }
        for(i = 1; i < d+1; i++){
            point[k][0] = i;
            point[k][1] = 0;
            q[k][0] = point[k][0];
            q[k][1] = point[k][1];
            k++;
        }
     int a = 0, b = 1;
       for(k = 0; k < w; k++){
            while(point[k][0] > 0 && point[k][1] <= w){
              if(map[point[k][0]][point[k][1]] == 1)
                 a += b;
              if(a % 2 == 0)
                point[k][0]--;
              else if (a % 2 == 1)
                point[k][1]++;
            }
            a = 0;
        }
        for(k = w; k < w + d; k++){
             while(point[k][0] <= d && point[k][1] > 0){
            if(map[point[k][0]][point[k][1]] == 1)
                 a += b;
              if(a % 2 == 0)
                point[k][1]--;
              else if (a % 2 == 1)
                point[k][0]++;
            }
            a = 0;
        }
        for(k = w + d ; k < 2 * w + d; k++){
             while(point[k][0] <= d && point[k][1] > 0){
            if(map[point[k][0]][point[k][1]] == 1)
                 a += b;
              if(a % 2 == 0)
                point[k][0]++;
              else if (a % 2 == 1)
                point[k][1]--;
            }
            a = 0;
        }
        for(k = 2 * w + d; k < 2 * w + 2 * d; k++){
             while(point[k][0] > 0 && point[k][1] <= w){
            if(map[point[k][0]][point[k][1]] == 1)
                 a += b;
              if(a % 2 == 0)
                point[k][1]++;
              else if (a % 2 == 1)
                point[k][0]--;
            }
            a = 0;
        }
   for(i = 0; i < 2 * w + 2 * d; i++)
    for(j = 0; j < 2 * w + 2 * d; j++){
    if(point[i][0] == q[j][0] && point[i][1] == q[j][1]){
       point[i][0] = j;
       point[i][1] = -1;
    }
   }

   for(i = 0; i < 2 * w + 2 * d; i++)
    printf("%d\n", point[i][0]);

}
