#include<stdio.h>
int main (void)
{
    int m, n, x1, y1, e1, n1, f1, x2, y2, e2, n2, f2, i = 0, j =0 ,k = 0, rx1, ry1, rx2, ry2;
    scanf("%d%d", &m, &n);
    scanf("%d%d%d%d%d", &x1, &y1, &e1, &n1, &f1);
    scanf("%d%d%d%d%d", &x2, &y2, &e2, &n2, &f2);
    rx1 = x1;
    ry1 = y1;
    rx2 = x2;
    ry2 = y2;
    int time = 1;
    int a, b;
    a = n1; b = e1;
    int c, d;
    c = e2; d = n2;
    while ((f1 > 0) || (f2 > 0) ){
        if(f1 > 0){
                        if(n1 >0){
                         ry1++;
                         f1--;
                         if(ry1 > n-1)
                          ry1 -= n;
                          n1--;
                        }
                        else if(n1 == 0 && e1 > 0){
                        rx1++;
                         f1--;
                        if(rx1 > m-1)
                        rx1 -= m;
                        e1--;
                        }
                        if(n1 == 0 && e1 == 0){
                            n1 = a;
                            e1 = b;
                        }
                }
        if (f2 > 0){
                if(e2 > 0){
                 rx2++;
                 f2--;
                 if(rx2 > m-1)
                 rx2 -= m;
                 e2--;
                }
                else if(e2 == 0 && n2 > 0){
                 ry2++;
                 f2--;
                 if(ry2 > n-1)
                 ry2 -= n;
                 n2--;
                }
                if(e2 == 0 && n2 == 0){
                    e2 = c;
                    n2 = d;
                }
        }
        if(rx1 == rx2 && ry1 == ry2){
            printf("robots explode at time ");
            printf("%d", time);
            k++;
            break;
        }
        time++;
    }
    if(k == 0)
    printf("robots will not explode");

    return 0;
}
