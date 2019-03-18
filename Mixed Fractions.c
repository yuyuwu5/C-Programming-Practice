#include<stdio.h>
main()
{
    int a, b, c, d, e, f, g, h, i, j, n, m;
    scanf("%d%d%d", &a, &b, &c);
    scanf("%d", &d);
    scanf("%d%d%d", &e, &f, &g);
    switch(d){
case 0 :
    if(a < 0)
        b = -b;
    if(e < 0)
        f = -f;
    h = (a * c * g + b * g +c * e * g + c * f)/ (c * g);
    i = (a * c * g + b * g +c * e * g + c * f - h * c * g);
    j = c * g;
    for(n = j; n > 0; n--)
    if ((j % n == 0) && (i % n == 0)){
        i = i / n;
        j = j / n;
    }
    if (i < 0)
        i = -i;
    if (i == 0)
        j = 1;
    break;
case 1:
    if(a < 0)
        b = -b;
    if(e < 0)
        f = -f;
    h = (a * c * g + b * g - c * e * g - c * f)/ (c * g);
    i = (a * c * g + b * g - c * e * g - c * f - h * c * g);
    j = c * g;
    for(n = j; n > 0; n--)
    if ((j % n == 0) && (i % n == 0)){
        i = i / n;
        j = j / n;
    }
    if (i < 0)
        i = -i;
    if (i == 0)
        j = 1;
    break;
case 2:
    if(a < 0)
        b = -b;
    if(e < 0)
        f = -f;
    h = (a * c * e * g + a * c * f + b * e * g + b * f) / (c * g);
    i = (a * c * e * g + a * c * f + b * e * g + b * f - h * c * g);
    j = c * g;
    for(n = j; n > 0; n--)
    if ((j % n == 0) && (i % n == 0)){
        i = i / n;
        j = j / n;
    }
    if (i < 0)
        i = -i;
    if (i == 0)
        j = 1;
    break;
case 3:
    if(a < 0)
        b = -b;
    if(e < 0)
        f = -f;
    h = (a * c * g + b * g) / ( c * e * g + c * f);
    i = (a * c * g + b * g- h * ( c * e * g + c * f));
    j = c * e * g + c * f;
    for(n = j; n > 0; n--)
    if ((j % n == 0) && (i % n == 0)){
        i = i / n;
        j = j / n;
    }
    if (i < 0)
        i = -i;
    if(j < 0)
        j = -j;
    if (i == 0)
        j = 1;
    break;
}
printf("%d\n", h);
printf("%d\n", i);
printf("%d\n", j);
}
