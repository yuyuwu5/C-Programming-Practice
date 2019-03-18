#include<stdio.h>
#include<string.h>
#include<ctype.h>
char topic[1000][128];
void check(char temp[50][50], int j)
{
    if(strlen(temp[j]) < 5){
        if(temp[j][0] == 'o' && temp[j][1] == 'f'){
            temp[j][0] = 0;
            temp[j][1] = 0;
        }
        if(temp[j][0] == 'a' && temp[j][1] == 't'){
            temp[j][0] = 0;
            temp[j][1] = 0;
        }
        if(temp[j][0] == 'a' && temp[j][1] == 'n' && temp[j][2] == 'd'){
            temp[j][0] = 0;
            temp[j][1] = 0;
            temp[j][2] = 0;
        }
        if(temp[j][0] == 't' && temp[j][1] == 'h' && temp[j][2] == 'e'){
            temp[j][0] = 0;
            temp[j][1] = 0;
            temp[j][2] = 0;
        }
    }
}
int main()
{
    int i = 0;
    int count = 0;
    char temp[50][50], deli[] = " ";
    while(scanf("%s", topic[i])!= EOF)
        i++;
   for(int j = 0; j < i; j++){
    char *ptr = topic[j];
    ptr = strtok(ptr, deli);
    while(ptr != NULL){
        strcpy(temp[count],ptr);
        check(temp, count);
        if(temp[count][0] != 0)
         printf("%c",toupper(temp[count][0]));
        count++;
        ptr = strtok(NULL,deli);
    }
    if(topic[j][strlen(topic[j])-1] == '.')
        printf("\n");
    count = 0;
   }
}


