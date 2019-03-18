#include<stdio.h>
int main(void)
{
    int r, c, i, j, k = 0, a[100][100], p[1000], q = 0;
    scanf("%d%d", &r, &c);
    for(i = 0; i < r; i++)
      for(j = 0; j < c; j++){
        scanf("%d", &a[i][j]);
      }
    for(i = 0; i < r; i++){
      for(j = 0; j < c; j++){
        if(i != 0 && j != 0 && i != r-1 && j != c-1){
            if(a[i][j] > a[i+1][j] && a[i][j] > a[i][j+1] && a[i][j] > a[i-1][j] && a[i][j] > a[i][j-1]){
                p[k] = a[i][j];
                k++;
                continue;
            }
        }
         if (i == 0 && j == 0)
            if(a[i][j] > a[i][j+1] && a[i][j] > a[i+1][j]){
             p[k] = a[i][j];
             k++;
              continue;
            }
         if (i == 0 && j == c-1)
            if(a[i][j] > a[i][j-1] && a[i][j] > a[i+1][j]){
             p[k] = a[i][j];
             k++;
              continue;
            }
         if (i == r-1 && j == 0)
            if(a[i][j] > a[i][j+1] && a[i][j] > a[i-1][j]){
             p[k] = a[i][j];
             k++;
              continue;
            }
         if (i == r-1 && j == c-1)
            if(a[i][j] > a[i][j-1] && a[i][j] > a[i-1][j]){
             p[k] = a[i][j];
             k++;
              continue;
            }
        if(i == 0 && j != 0 && j != c-1){
             if(a[i][j] > a[i+1][j] && a[i][j] > a[i][j+1] && a[i][j] > a[i][j-1]){
                p[k] = a[i][j];
                k++;
                 continue;
            }
        }
         if(i == r-1 && j != 0 && j != c-1){
             if(a[i][j] > a[i][j+1] && a[i][j] > a[i][j-1] && a[i][j] > a[i-1][j]){
                p[k] = a[i][j];
                k++;
                 continue;
            }
        }
         if(j == 0 && i != 0 && i != r-1){
             if(a[i][j] > a[i+1][j] && a[i][j] > a[i][j+1] && a[i][j] > a[i-1][j]){
                p[k] = a[i][j];
                k++;
                 continue;
            }
        }
        if(j == c-1 && i != 0 && i != r-1){
             if(a[i][j] > a[i+1][j] && a[i][j] > a[i][j-1] && a[i][j] > a[i-1][j]){
                p[k] = a[i][j];
                k++;
                 continue;
            }
        }
      }
}

for(q = 0; q < k; q++)
    printf("%d\n", p[q]);
return 0;
}
