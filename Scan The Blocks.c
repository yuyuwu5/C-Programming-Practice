#include<stdio.h>
main()
{
    int n;
    while (scanf("%d", &n) != EOF){
        int max, min;
        scanf("%d",&max);
        min = max;
        n -= 1;
        int num;
        while (n > 0 && scanf("%d", &num) != EOF){
            if (num > max)
                max = num;
            if(num < min)
                min = num;
            n -= 1;
        }
        if (n == 0)
            printf("%d\n", max);
        else
            printf("%d\n", min);
    }
}
