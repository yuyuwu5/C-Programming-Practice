#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char topic[1000],past[1000];
    while(scanf("%s",topic)!=EOF){
        int length=strlen(topic);
        int conti=0,not_print=0;
        for(int i =0;i<length;i++){
            if(isdigit(topic[i])){
                if(isalpha(topic[i-1]) && topic[i]=='0' && isdigit(topic[i+1])){not_print=1;}
                if(not_print && topic[i]=='0'&& isdigit(topic[i+1])){not_print=1;}
                else{conti++;printf("%c",topic[i]);}
                }
            if(conti>0){if(isalpha(topic[i])){printf("\n");conti=0;not_print=0;}}
        }
        if(isdigit(topic[length-1])){printf("\n");}

    }
}