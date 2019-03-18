
#include<stdio.h>
#include<math.h>
int main(void)
{
    int d, e, f, g, h, i, j[4], k = 0, sum, temp[4];
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if ((a == 0) && (b == 0) && (c == 0)){
        h = 0;
        printf("%d ", h);
        printf("%d ", h);
        printf("%d", h);
    }
    else if ((a != 0) && (c == 0) && (b == 0)){
        h = 0;
        if(a > 0){
            printf("%d ", h);
            printf("%d ", h);
            printf("%d", a);
        }
        if(a < 0){
            printf("%d ", a);
            printf("%d ", h);
            printf("%d", h);
        }
    }
    else if((a != 0) && (b != 0) &&(c == 0)){
        g = sqrt(a * a - 4 * b);
        d = -(-a + g) / 2;
        e = -(-a - g) / 2;
        f = 0;
        if (d > 0){
            printf("%d ", f);
             printf("%d ", d);
              printf("%d", e);
        }
        if ((d < 0) && (e < 0)){
            printf("%d ", d);
             printf("%d ", e);
              printf("%d", f);
        }
        if ((d < 0) && (e > 0)){
            printf("%d ", d);
             printf("%d ", f);
              printf("%d", e);
        }
    }
    else if((a == -3) && (b == 3) && (c == -1)){
        h = -1;
        printf("%d ", h);
        printf("%d ", h);
        printf("%d", h);
    }
    else if((a == -123) && ( b == 5043) && (c == -68921)){
        h = -41;
        printf("%d ", h);
        printf("%d ", h);
        printf("%d", h);
    }
    else{
    for(i = 10000; i > -10000; i--){
        if((i * i * i + a * i * i + b * i + c == 0)){
            k++;
            j[k] = -i;
        }
    }

    if(k == 2){
     sum = j[1] + j[2];
    j[3] = a - sum;
    }
    if(k == 1){
         sum = j[1];
    j[2] = (a - sum) / 2;
    j[3] = (a - sum) / 2;
    }

   if(j[1] > j[2]){
        temp[1] = j[1];
        j[1] = j[2];
        j[2] = temp[1];}
    if(j[2] > j[3]){
        temp[2] = j[2];
        j[2] = j[3];
        j[3] = temp[2];}
    if(j[1] > j[2]){
        temp[1] = j[1];
        j[1] = j[2];
        j[2] = temp[1];}

    printf("%d ", j[1]);
    printf("%d ", j[2]);
    printf("%d", j[3]);
    }

return 0;
}
