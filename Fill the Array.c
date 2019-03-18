#include <stdio.h>
//#include "fill_array.h"
void fill_array(int *ptr[], int n)
{
    int fill[10000], control[10000] = {0}, i = 0, j, k = 0;
    for(i = 0; i < 10000; i++)
        fill[i] = -1;
    int max = 0, pole[10000];
    for(j = 0; j < n; j++){
        *ptr[j] += j;
         fill[ptr[j]-*ptr] = *ptr[j];
         control[ptr[j]-*ptr] = 1;
         if(max < ptr[j]-*ptr)
            max = ptr[j]-*ptr;
        }
    max++;
    for(j = 0; j < max; j++)
        if(fill[j] != -1){
            pole[k] = j;
            k++;
        }
    for(j = 0; j < max; j++){
        int r;
         if(control[j] == 0){
             for(i = 0; i < k; i++)
                if(j > pole[i] && j < pole[i+1]){
                   r = i;
                   break;
         }
         fill[j] = fill[pole[r]] + fill[pole[r+1]];
         }
     }
     for(j = 0; j < max; j++)
        *(*ptr+j)=fill[j];
}
int main() {
    int arr[100] = {};
    int *ptr[100];
    int n = 6, m = 0;
    int A[100] = {0, 5, 6, 9, 3, 12};
    for (int i = 0; i < n; i++) {
        ptr[i] = &arr[A[i]];
        if (A[i] > m)    m = A[i];
    }
    fill_array(ptr, n);
    for (int i = 0; i <= m; i++)
        printf("%d%c", arr[i], " \n"[i==m]);
    return 0;
}

