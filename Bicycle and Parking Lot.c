#include<stdio.h>
int main()
{
    int n, m, x1[20], y1[20], x2, y2, cap[20], i, j, distance[20], min = 100000000, p, q[20000] = {0},k,l;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d%d%d", &x1[i], &y1[i], &cap[i]);
    scanf("%d", &m);

    for(j = 0; j < m; j++){
        scanf("%d%d", &x2, &y2);
        for(i = 0; i < n; i++){
            if (cap[i] > 0){
                    k = (x2 - x1[i]);
                    l = (y2 - y1[i]);
                    if (k < 0)
                        k = -k;
                    if (l < 0)
                        l = -l;
            distance[i] = k + l;
            if(min > distance[i]){
                   min = distance[i];
                   p = i;
                }
             else if (min == distance[i]){
               if(x1[p] > x1[i]){
                   p = i;
               }
             else if(x1[p] == x1[i])
                if (y1[p] > y1[i]){
                   p = i;
                }
            }
            }
            else
            continue;
    }
                   cap[p]--;
                   q[p]++;
                   min = 100000000;
                   continue;
    }
    for(i = 0; i < n; i++)
        printf("%d\n", q[i]);

    }
