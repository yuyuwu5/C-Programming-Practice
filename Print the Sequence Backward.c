#include<stdio.h>
int main(void)
         {
             int n, i, j, array[1000];
             scanf("%d", &n);
             for(i = 0; i < n; i++){
                scanf("%d", &array[i]);
             }
             for(j = n - 1; j >= 0; j--){
                  if (j == 0)
                printf("%d", array[j]);
                   else
                    printf("%d ", array[j]);
             }
         }
