#include <stdio.h>
//#include "evaluate_f.h"
int evaluate_f(int *iptr[], int n, int *index)
{
    int i, max = -100000000;
    for(i = 0; i < n; i++)
    if(max < 4 * (*iptr[i]) - 6 * (*(iptr[i]+1))){
        max = 4 * (*iptr[i]) - 6 * (*(iptr[i]+1));
        *index = i;
    }

    return max;
}
int main(){
  int a[] = { 9, 7 };
  int b[] = { 3, 2 };
  int c[] = { 3, 2 };
  int d[] = { 9, 7 };
  int *iptr[] = { a, b, c, d };
  int max, index;
  max = evaluate_f(iptr, 4, &index);
  printf("%d %d\n", max, index);
}
