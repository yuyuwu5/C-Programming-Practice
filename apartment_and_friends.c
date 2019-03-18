#include<stdio.h>
#include<stdlib.h>
int list[13],n,m,ask[50][2],min=100000;
int check(int now){
	int distance=0;
	for(int i=0;i<m;i++){
		int start=0,level=0;
		for(int j=0;j<now;j++){
			if(start)distance++;
			if(level==0){
				if(list[j]==ask[i][0]||list[j]==ask[i][1]){
					start=1;
					level++;
				}
			}else if(level==1)if(list[j]==ask[i][1]||list[j]==ask[i][0])break;
		}
	}return distance;
}
void sort(int now){
	if(min==105)return;
	if(now==n){
		if(min>check(n))min=check(n);
		return;
	}int tmp;
	if(n%2)tmp=(n+1)/2;
	else tmp=n/2;
	for(int i=0;i<n;i++){
		if(now==0&&i>tmp)return;
		int walk=1;
		for(int j=0;j<now;j++){
			if(list[j]==i)walk=0;;
		}if(walk){
			list[now]=i;
			if(now>tmp){
				int k=check(now+1);
				if(k>min)return;
			}sort(now+1);
		}
	}list[now]=-1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)scanf("%d%d",&ask[i][0],&ask[i][1]);
	sort(0);
	printf("%d\n",min);
}

