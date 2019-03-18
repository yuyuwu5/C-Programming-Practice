#include<stdio.h>
#include<ctype.h>
int main(void)
{
    int k[26] = {0}, i;
    char c;
    while(scanf("%c", &c) != EOF){
        if(isalpha(c)){
            if(c < 91)
                k[c-'A']++;
            else
                k[c-'a']++;
        }
    }
    for(i = 0; i < 26; i++)
        printf("%d\n", k[i]);

}
