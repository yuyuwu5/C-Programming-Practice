#include<stdio.h>
main()
{
    int n, i, j, l = 0, k = 0, m = 0;
    scanf("%d", &n);
     for(i = 0; i < n; i++){
        scanf("%d", &j);
        if(j % 3 == 0)
            l++;
        if(j % 3 == 1)
            k++;
        if(j % 3 == 2)
            m++;
     }
        printf("%d ", l);
        printf("%d ", k);
        printf("%d", m);
}
