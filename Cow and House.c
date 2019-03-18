#include<stdio.h>
int main(void)
{
    double a, b, c;
    double pi = 3.1415926, area;
    scanf("%lf%lf%lf", &a, &b, &c);

    if(c <= a && c <= b){
      area = c * c * pi * 3 / 4;
    }
    else if(c > a && c <= b){
      area = c * c * pi * 3 / 4 + (c - a) * (c - a) * pi /4;
    }
     else if(c > b && c <= a){
      area = c * c * pi * 3 / 4 + (c - b) * (c - b) * pi /4;
    }
    else if(c > a && c > b){
      area = c * c * pi * 3 / 4 + (c - a) * (c - a) * pi /4 + (c - b) * (c - b) * pi /4;
    }
     printf("%f\n", area);
}
