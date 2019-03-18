#include<stdio.h>
main()
{
    int n, odd[1000], even[1000], i, j = 0, k = 0, l;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
    scanf("%d", &l );
    if(l % 2 == 0){
       even[j] = l;
       j++;
    }
    if(l % 2 != 0){
        odd[k] = l;
        k++;
}
    }
    for(i = 0; i < k; i++){
        if(i != k - 1)
        printf("%d ", odd[i]);
        else
            printf("%d", odd[i]);
    }
    printf("\n");
     for(i = 0; i < j; i++){
        if(i != j - 1)
        printf("%d ", even[i]);
        else
            printf("%d", even[i]);

}
}
