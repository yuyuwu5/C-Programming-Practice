#include<stdio.h>
main()
{
    int x1, x2, x3, x4, y1, y2, y3, y4, k;
    scanf("%d", &x1);
    scanf("%d", &y1);
    scanf("%d", &x2);
    scanf("%d", &y2);
    scanf("%d", &x3);
    scanf("%d", &y3);
    scanf("%d", &x4);
    scanf("%d", &y4);
    if ((x1 * y2 - y1 * x2 > 0) && (x2 * y3 - y2 * x3 > 0) &&
        (x3 * y4 - y3 * x4 > 0) && (x4 * y1 - y4 * x1 > 0))
            k = 1;
    else
        k = 0;
    printf("%d\n", k);

}
