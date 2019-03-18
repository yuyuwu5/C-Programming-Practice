#include<stdio.h>
int main(void)
{
    int x[100], y[100], output, k, temp, maxx = -10000, maxy = -10000, minx = 10000, miny = 10000, a, b, c, d;
    int i = 0, j = 0;
    while(scanf("%d%d", &x[i], &y[i]) != EOF){
        if(maxx < x[i])
            maxx = x[i];
        if(minx > x[i])
            minx = x[i];
        if(maxy < y[i])
            maxy = y[i];
        if(miny > y[i])
            miny = y[i];
        i++;
    }
    output = (maxx - minx) * (maxy - miny);
   printf("%d", output);
}
