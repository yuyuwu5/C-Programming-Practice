#include<stdio.h>
int n,m,map[100][100],list[100];
int rec(int now,int choose[],int limit){
	if(now==m){
		for(int i=0;i<m;i++)printf("%d%c",list[i]," \n"[i==m-1]);
		return 1;
	}for(int i=0;i<limit-(m-now)+1;i++){
		list[now]=choose[i];
		int Choose[100],t=0;
		for(int j=i+1;j<limit;j++){
			if(map[choose[i]][choose[j]]==0)Choose[t++]=choose[j];
		}if(rec(now+1,Choose,t))return 1;
	}return 0;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		int choose[100];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&map[i][j]);
				if(map[i][j]==0&&i==j)map[i][j]=1;
			}choose[i]=i;
		}if(!rec(0,choose,n))puts("no solution");
	}
}
	
