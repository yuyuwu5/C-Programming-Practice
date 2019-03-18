#include<stdio.h>
int map[11][11]={0},match[11][11]={0};
int inside(int y,int x,int l){
	return y>=0&&y<l&&x>=0&&x<l;
}int sum(int y,int x,int k,int M[11][11],int l){
	int count=0;
	for(int i=y;i<y+k;i++)for(int j=x;j<x+k;j++)if(inside(i,j,l))count+=M[i][j];
	return count;
}
int Match(int y,int x,int k,int l){
	int not=0;
	for(int i=y;i<y+k;i++){
		for(int j=x;j<x+k;j++){
			if(inside(i,j,l)){
				if(map[i][j]!=match[i-y][j-x])not++;
			}else not++;
		}
	}return not;
}
int Abs(int k){
	if(k<0)return -k;
	return k;
}
int main(){
	int n,k,m,d;
	scanf("%d%d%d%d",&n,&k,&m,&d);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&map[i][j]);
	for(int i=0;i<k;i++)for(int j=0;j<k;j++)scanf("%d",&match[i][j]);
	int match_y=-1,match_x=-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(inside(i+k-1,j+k-1,n)){
				if(Abs(sum(i,j,k,map,n)-sum(0,0,k,match,k))<=d){
					if(Match(i,j,k,n)<=m){
						match_y=i;
						match_x=j;
					}
				}
			}
		}
	}printf("%d %d\n",match_y,match_x);
}
	
