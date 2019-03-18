#include<stdio.h>
int n,map[2][100][100]={0},times[100][100]={0},max=0,max_y,max_x;
int inside(int y,int x){
	return y>=0&&y<n&&x>=0&&x<n;
}void check(int y,int x,int now){
	int nearby=0;
	for(int i=y-1;i<=y+1;i++){
		for(int j=x-1;j<=x+1;j++){
			if(i==y&&j==x)continue;
			if(inside(i,j)){
				if(map[now][i][j]==1)nearby++;
			}
		}
	}if(map[now][y][x]==0){
		if(nearby==3){
			times[y][x]++;
			if(max<=times[y][x]){
				max=times[y][x];
				max_y=y;
				max_x=x;
			}
			map[(now+1)%2][y][x]=1;
		}else map[(now+1)%2][y][x]=0;
		return;
	}if(map[now][y][x]==1){
		if(nearby<2||nearby>3){
			map[(now+1)%2][y][x]=0;
		}else if(nearby==2||nearby==3){
			times[y][x]++;
			if(max<=times[y][x]){
				max=times[y][x];
				max_y=y;
				max_x=x;
			}
			map[(now+1)%2][y][x]=1;
		}
		return;
	}
}
void print(int k){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d%c",map[k][i][j]," \n"[j==n-1]);
		}
	}
}
int main(){
	int time;
	scanf("%d%d",&n,&time);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++){
		scanf("%d",&map[0][i][j]);
		if(map[0][i][j]==1){
			times[i][j]=1;
			if(max<=times[i][j]){
				max=1;
				max_y=i;
				max_x=j;
			}
		}
	}for(int i=0;i<time;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				check(j,k,i%2);
			}
		}
	}print(time%2);
	printf("%d %d\n",max_y+1,max_x+1);
}
