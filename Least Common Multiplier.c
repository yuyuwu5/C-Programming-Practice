#include<stdio.h>
int spilt (int i, int j)
{
    int o, p, spilt;
    for(o = i; o > 0; o--){
        if(i % o == 0 && j % o ==0){
            p = o;
            break;
        }
    }
    spilt = i * j / p;
    return spilt;
}


int main(void)
{
    int a, j, k, l, s[100], h[100] = {0}, sp;
    int i = 0, p = 1, q = 0;
    while(scanf("%d", &a) != EOF){
       if(h[a] == 0){
         h[a] = 1;
         s[i] = a;
         i++;
       }
         else
            continue;
    }
    for(l = 0; l < i-1; l++){
        sp = spilt(s[l], s[l+1]);
        s[l+1] = sp;
    }
    printf("%d\n", sp);
}
