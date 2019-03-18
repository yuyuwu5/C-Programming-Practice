#include<stdio.h>
main()
{
    int n, i, k;
    scanf("%d",&n);
    scanf("%d", &i);
    switch(i){
case 0:
    k = 1;
    break;
case 1:
    k = n ;
    break;
case 2:
    k = n * n;
    break;
case 3:
    k = n * n * n;
    break;
case 4:
    k = n * n * n * n;
    break;
case 5:
    k = n * n * n * n * n;
    break;

}
printf("%d\n", k);
}
