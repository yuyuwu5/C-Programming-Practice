#include<stdio.h>
int max (int array[5][5])
{
    int max = 0, i, j;
    for(i = 0; i < 5; i++)
     for(j = 0; j < 5; j++){
        if(max < array[i][j])
            max = array[i][j];
    }
    return max;
}

int main()
 {
    int i, j;
    int array[5][5];
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
              scanf("%d", &(array[i][j]));
      printf("%d\n", max(array));
    return 0;
}
