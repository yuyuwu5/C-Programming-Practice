#include<stdio.h>
int main()
{
    int c[100005],i, n, j = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &c[i]);
        if(c[i] == 0)
            j++;
    }
    for(i = 0; i < n; i++)
        if(c[i]!= 0)
        printf("%d ",c[i]);
    for(i = 0; i < j; i++){
        if(i == j-1)
        printf("0");
        else
            printf("0 ");
    }
}
