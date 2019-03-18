#include "intersection.h"
#include<stdio.h>
void intersection(int map[100][100], int result[4])
{
	int computation[102][102] = {0}, i, j, k;
	for(i = 0; i < 4; i++)
        result[i] = 0;
	for(i = 0; i < 100 ; i++)
		for(j = 0; j < 100 ; j++)
			computation[i+1][j+1] = map[i][j];
	for(i = 1 ; i < 101 ; i++){
		for(j = 1 ; j < 101 ; j++){
			if(computation[i][j] == 1){
			k = computation[i-1][j] + computation[i+1][j] + computation[i][j-1] + computation[i][j+1];
			if(k > 0){
			if(k == 2){
			if((computation[i-1][j]+computation[i][j-1]==2)||(computation[i-1][j]+computation[i][j+1]==2)||
               (computation[i+1][j]+computation[i][j-1]==2)||(computation[i+1][j]+computation[i][j+1]==2))
				result[2]++;
			}
			else
			result[4-k]++;
			}
			}
			else
                continue;
		}
	}
	return;
}


int main(void)
 {
  int result[4], map[100][100] = {0}, i, j;
     for(i = 0; i < 100; i++)
      for(j = 0; j < 100; j++)
        scanf("%d", &map[i][j]);
     intersection(map, result);

        for(i = 0; i < 4; i++)
        printf("%d\n", result[i]);
}
