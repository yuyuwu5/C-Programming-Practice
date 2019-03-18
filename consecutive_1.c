#include<stdio.h>
int map[1000][1000]={0};
int main(){
	int N,max=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)scanf("%d",&map[i][j]);
	for(int i=0;i<N;i++){
		int tmp=0;
		for(int j=0;j<N;j++){
			if(map[i][j]==1){
				tmp++;
			}else{
				if(max<tmp)max=tmp;
				tmp=0;
			}
		}
		if(max<tmp)max=tmp;
	}
	
	for(int i=0;i<N;i++){
		int tmp=0;
		for(int j=0;j<N;j++){
			if(map[j][i]==1){
				tmp++;
			}else{
				if(max<tmp)max=tmp;
				tmp=0;
			}
		}
		if(max<tmp)max=tmp;
	}
	for(int i=0;i<N;i++){
		int tmp=0,y=0,x=i;
		while(y<N&&x<N){
			if(map[y][x]==1){
				tmp++;
			}else{
				if(max<tmp)max=tmp;
				tmp=0;
			}y++;
			x++;
		}
		if(max<tmp)max=tmp;
	}
	for(int i=0;i<N;i++){
		int tmp=0,y=i,x=0;
		while(y<N&&x<N){
			if(map[y][x]==1){
				tmp++;
			}else{
				if(max<tmp)max=tmp;
				tmp=0;
			}y++;
			x++;
		}
		if(max<tmp)max=tmp;
	}
	printf("%d\n",max);
}

