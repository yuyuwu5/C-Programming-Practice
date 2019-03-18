#include<stdio.h>
int map[999][999]={0};
void pre(){
	int k=999/2;
	map[k][k]=1;
	map[k][k-1]=2;
	int total=999*999-2;
	int now_y=k-1,now_x=k-1,now=3;
	while(total>0){
		//up
		while(map[now_y][now_x+1]!=0){
			map[now_y][now_x]=now++;
			total--;
			now_y--;
			if(total==0)break;
		}
		//right
		while(map[now_y+1][now_x]!=0){
			map[now_y][now_x]=now++;
			total--;
			now_x++;
			if(total==0)break;
		}
		//down
		while(map[now_y][now_x-1]!=0){
			map[now_y][now_x]=now++;
			total--;
			now_y++;
			if(total==0)break;
		}
		//left
		while(map[now_y-1][now_x]!=0){
			map[now_y][now_x]=now++;
			total--;
			now_x--;
			if(total==0)break;
		}if(total==0)break;
	}
	
}
#include <stdio.h>
#include <assert.h>

#define MAXLEN 1000

static int snake[MAXLEN*MAXLEN];
static int result[MAXLEN*MAXLEN];
int done=0;
void SpiralSnake(int N, int *snake, int *result){
	if(!done){
		pre();
		done=1;
	}int k=999/2,tmp=N/2,now=0;
	for(int i=k-tmp;i<=k+tmp;i++){
		for(int j=k-tmp;j<=k+tmp;j++){
			//printf("%d ",map[i][j]);
			result[now++]=snake[map[i][j]-1];
		}//puts("");
	}
}
int main(){
    int N;
    while(scanf("%d", &N)!=EOF){
        for(int i=0; i<N*N; i++)
              assert(scanf("%d", &snake[i])==1);
        SpiralSnake(N, snake, result);
        for(int i=0; i<N*N; i++)
             printf("%d%c", result[i], " \n"[i==N*N-1]);
    }
    return 0;
}
