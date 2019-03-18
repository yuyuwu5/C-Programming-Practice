#include<stdio.h>
int main(void)
{
    int n, m, l, w, map[500][500] = {0}, a, obstaclex[2500], obstacley[2500],tankx = 0, tanky = 0;
    int i, j, instruction;
    int flag = 0;
    scanf("%d%d%d%d", &n, &m, &l, &w);
    scanf("%d", &a);
    for(i = 0; i < a; i++)
        scanf("%d%d", &obstaclex[i], &obstacley[i]);
    for(i = 0; i < a; i++)
        map[obstacley[i]][obstaclex[i]] = 2;
    while(scanf("%d", &instruction) != EOF){
        if(instruction == 0){
            int count = 0;
            for(i = tanky; i < tanky + l; i++)
                for(j = tankx; j < tankx + w; j++)
                   map[i][j] = 1;
           for(i = 0; i < n; i++)
            for(j = 0; j < m; j++){
                if(count % m == m-1){
                  printf("%d\n", map[i][j]);
                  count++;
                  }
                  else{
                    printf("%d", map[i][j]);
                    count++;
                  }
                }
                    count = 0;
                    continue;
            }
        else if(instruction == 1){
            if(tankx+w < m){
            tankx++;
            for(i = tanky; i < tanky + l; i++)
                if(map[i][tankx + w-1] == 2)
                    flag++;
            if(flag > 1)
                tankx--;
            else{
                for(i = tanky; i < tanky + l; i++)
                    map[i][tankx-1] = 0;
            }
            flag = 0;
            continue;
        }
        else
            continue;
        }
        else if(instruction == 2){
            if(tanky+l < n){
            tanky++;
            for(j = tankx; j < tankx + w; j++)
                if(map[tanky + l -1][j] == 2)
                flag++;
            if(flag > 1)
                tanky--;
            else{
                for(j = tankx; j < tankx + w; j++)
                    map[tanky-1][j] = 0;
            }
            flag = 0;
            continue;
            }
            else
                continue;
        }
        else if (instruction == 3){
            if(tankx-1 >= 0){
            tankx--;
            for(i = tanky; i < tanky + l; i++)
                if(map[i][tankx] == 2)
                    flag++;
            if(flag > 1)
                tankx++;
            else {
            for(i = tanky; i < tanky + l; i++)
                    map[i][tankx + w] = 0;
                }
                flag = 0;
            continue;
            }
            else
            continue;
        }
        else if(instruction == 4){
            if(tanky-1 >= 0){
             tanky--;
            for(j = tankx; j < tankx + w; j++)
                if(map[tanky][j] == 2)
                flag++;
            if(flag > 1)
                tanky++;
            else{
                for(j = tankx; j < tankx + w; j++)
                    map[tanky + l][j] = 0;
            }
            flag = 0;
            continue;
        }
           else
            continue;
        }
       else if(instruction == 5){
            if(tankx+w < m && tanky+l < n){
             tankx++;
             tanky++;
            for(i = tanky; i < tanky + l; i++)
                if(map[i][tankx + w -1] == 2)
                flag++;
            for(j = tankx; j < tankx + w; j++)
                if(map[tanky + l -1][j] == 2)
                flag++;
            if(map[tanky + l -1][tankx + w -1] == 2)
                flag--;
            if(flag > 1){
                tankx--;
                tanky--;
            }
            else{
                 for(i = tanky-1; i < tanky + l-1; i++)
                    map[i][tankx-1] = 0;
                 for(j = tankx-1; j < tankx + w-1; j++)
                    map[tanky-1][j] = 0;
            }
            flag = 0;
            continue;
        }
        else
            continue;
        }
    }
    return 0;
}
