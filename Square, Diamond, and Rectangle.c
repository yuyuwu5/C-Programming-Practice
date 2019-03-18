#include<stdio.h>
main()
{
    int a, x1[100001], x2[100001], x3[100001], x4[100001], y1[100001], y2[100001], y3[100001], y4[100001], tempx[100000], tempy[100000], n, k, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d%d%d%d%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i], &x3[i], &y3[i], &x4[i], &y4[i]);
        if ((x2[i] - x1[i]) * (y3[i] - y1[i]) - (x3[i] - x1[i]) * (y2[i] - y1[i]) < 0){
            tempx[i] = x2[i];
            x2[i] = x3[i];
            x3[i] = tempx[i];
            tempy[i] = y2[i];
            y2[i] = y3[i];
            y3[i] = tempy[i];
    }

        if ((x2[i] - x1[i]) * (y4[i] - y1[i]) - (x4[i] - x1[i]) * (y2[i] - y1[i]) < 0){
            tempx[i] = x2[i];
            x2[i] = x4[i];
            x4[i] = tempx[i];
            tempy[i] = y2[i];
            y2[i] = y4[i];
            y4[i] = tempy[i];

    }
    if ((x3[i] - x1[i]) * (y4[i] - y1[i]) - (x4[i] - x1[i]) * (y3[i] - y1[i]) < 0){
            tempx[i] = x4[i];
            x4[i] = x3[i];
            x3[i] = tempx[i];
            tempy[i] = y4[i];
            y4[i] = y3[i];
            y3[i] = tempy[i];

    }
    if (((x2[i] - x1[i]) * (x4[i] - x1[i]) + (y2[i] - y1[i]) * (y4[i] - y1[i]) == 0) &&
        ((x2[i] - x3[i]) * (x4[i] - x3[i]) + (y2[i] - y3[i]) * (y4[i] - y3[i]) == 0) &&
        ((x3[i] - x2[i]) * (x1[i] - x2[i]) + (y3[i] - y2[i]) * (y1[i] - y2[i]) == 0) ){
        if (((x2[i] - x1[i]) * (x2[i] - x1[i]) + (y2[i] - y1[i]) * (y2[i] - y1[i]) ==
            (x3[i] - x2[i]) * (x3[i] - x2[i]) + (y3[i] - y2[i]) * (y3[i] - y2[i])) &&
             ((x4[i] - x3[i]) * (x4[i] - x3[i]) + (y4[i] - y3[i]) * (y4[i] - y3[i]) ==
            (x4[i] - x1[i]) * (x4[i] - x1[i]) + (y4[i] - y1[i]) * (y4[i] - y1[i])) &&
             ((x2[i] - x1[i]) * (x2[i] - x1[i]) + (y2[i] - y1[i]) * (y2[i] - y1[i]) ==
            (x4[i] - x1[i]) * (x4[i] - x1[i]) + (y4[i] - y1[i]) * (y4[i] - y1[i])))
            printf("square\n");
        if (((x2[i] - x1[i]) * (x2[i] - x1[i]) + (y2[i] - y1[i]) * (y2[i] - y1[i]) ==
            (x3[i] - x4[i]) * (x3[i] - x4[i]) + (y3[i] - y4[i]) * (y3[i] - y4[i])) &&
             ((x2[i] - x3[i]) * (x2[i] - x3[i]) + (y2[i] - y3[i]) * (y2[i] - y3[i]) ==
            (x4[i] - x1[i]) * (x4[i] - x1[i]) + (y4[i] - y1[i]) * (y4[i] - y1[i])) &&
             ((x2[i] - x1[i]) * (x2[i] - x1[i]) + (y2[i] - y1[i]) * (y2[i] - y1[i]) !=
            (x4[i] - x1[i]) * (x4[i] - x1[i]) + (y4[i] - y1[i]) * (y4[i] - y1[i])))
            printf("rectangle\n");
    }
    else if (((x2[i] - x1[i]) * (x2[i] - x1[i]) + (y2[i] - y1[i]) * (y2[i] - y1[i]) ==
            (x3[i] - x2[i]) * (x3[i] - x2[i]) + (y3[i] - y2[i]) * (y3[i] - y2[i])) &&
             ((x4[i] - x3[i]) * (x4[i] - x3[i]) + (y4[i] - y3[i]) * (y4[i] - y3[i]) ==
            (x4[i] - x1[i]) * (x4[i] - x1[i]) + (y4[i] - y1[i]) * (y4[i] - y1[i])) &&
             ((x2[i] - x1[i]) * (x2[i] - x1[i]) + (y2[i] - y1[i]) * (y2[i] - y1[i]) ==
            (x4[i] - x1[i]) * (x4[i] - x1[i]) + (y4[i] - y1[i]) * (y4[i] - y1[i])))
            printf("diamond\n");
        else
            printf("other\n");
    }
}

