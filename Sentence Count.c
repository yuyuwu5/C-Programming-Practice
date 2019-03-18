#include<stdio.h>
int main(void)
{
    char c[200000];
    int i = 0, total = 0;
    while(scanf("%c", &c[i]) != EOF)
        i++;
    for(int j = 0; j < i; j++){
        if(c[j] == '.'){
            if(c[j+1] == '\n')
                total++;
            else if(c[j+1] == ' ' && c[j+2] == ' ')
                total++;
            else if(c[j+1] == '\0')
                total++;
        }
    }
    printf("%d", total);
}
