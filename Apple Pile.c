#include<stdio.h>
int main(void)
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n%d\n", (a + b) * (b - a + 1) / 2,  a + b + 2 * (b - a + 1) - 4);
}
