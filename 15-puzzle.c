#include<stdio.h>
int map[4][4],move,stack[16],get;
int check(){
	int diff=0;
	for(int i=0;i<15;i++){
		if(map[i/4][i%4]!=i+1)diff++;
	}return diff;
}void swap(int y1,int x1,int y2,int x2){
	int t=map[y1][x1];
	map[y1][x1]=map[y2][x2];
	map[y2][x2]=t;
}int inside(int y,int x){
	return y<4&&y>=0&&x<4&&x>=0;
}void rec(int y,int x,int now){
	if(get)return;
	int tmp=check();
	if(tmp==0){
		get=1;
		return;
	}if(now+tmp>move)return;
	for(int i=0;i<4;i++){
		if(i==0&&inside(y-1,x)){
			swap(y,x,y-1,x);
			rec(y-1,x,now+1);
			swap(y,x,y-1,x);
		}
		else if(i==1&&inside(y+1,x)){
			swap(y,x,y+1,x);
			rec(y+1,x,now+1);
			swap(y,x,y+1,x);
		}
		else if(i==2&&inside(y,x-1)){
			swap(y,x,y,x-1);
			rec(y,x-1,now+1);
			swap(y,x,y,x-1);
		}
		else if(i==3&&inside(y,x+1)){
			swap(y,x,y,x+1);
			rec(y,x+1,now+1);
			swap(y,x,y,x+1);
		}
	}
}
int main(){
	while(scanf("%d",&move)!=EOF){
		int y,x;
		get=0;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				scanf("%d",&map[i][j]);
				if(map[i][j]==0)y=i,x=j;
			}
		}rec(y,x,0);
		printf("%d\n",get);
	}
}
