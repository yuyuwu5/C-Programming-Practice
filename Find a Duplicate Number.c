#include<stdio.h>
int main(void)
{
    int n, c[100000], i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &c[i]);
     for(i = 0; i < n; i++){
         for(j = n-1; j >= 0; j--){
         if(i != j){
         if(c[i] == c[j]){
         printf("%d", c[i]);
         break;
     }
         }
     }
     if(c[i] == c[j])
         break;
     }

}
