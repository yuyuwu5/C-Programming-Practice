#include<stdio.h>
int main(void)
{
    int part = 1, i, j, p[10000];
    while(scanf("%d", &i) != EOF){
    for(j = 0; j < i; j++)
        scanf("%d", &p[j]);
    for(j = 0; j < i-1; j++){
        if(p[j] != p[j+1])
            part++;
    }
    printf("%d\n", part);
    part = 0;
    }
}
