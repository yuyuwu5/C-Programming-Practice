#include<stdio.h>
#include<ctype.h>
int main(void)
{
    int j= 0, i;
    char d, c[1024];
    while(scanf("%c", &d) != EOF){
        c[j] = d;
        if(c[j] == '-')
            break;
        else if(c[j] == '\n'){
            if((c[j-1]-'0')% 2 == 0)
                 printf("yes ");
            else
                printf("no ");
            int sum = 0;
            for(i = 0; i < j; i++)
                sum += (c[i]-'0');
            if(sum % 3 == 0)
                printf("yes ");
            else
                printf("no ");
            sum = 0;
           if((c[j-1]-'0') % 5 == 0)
                 printf("yes ");
            else
                printf("no ");

            int even = 0, odd = 0;
            for(i = 0; i < j; i++){
                if(i % 2 == 0)
                    even += (c[i] -'0');
                else
                    odd += (c[i]-'0');
            }
            if((even - odd) % 11 == 0)
                printf("yes\n");
            else
                printf("no\n");
        even = 0;
        odd = 0;
        j = 0;
        }
        else
        j++;
        }
}

