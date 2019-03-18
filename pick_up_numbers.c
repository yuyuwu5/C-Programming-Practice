#include<stdio.h>
int k,n,m,candidate[25],count=0;
void rec(int many,int sum,int index){
	if(sum>m||index>=n)return;
	rec(many,sum,index+1);
	if(sum+candidate[index]<=m){
		if(many+1>=k)count++;
		rec(many+1,sum+candidate[index],index+1);
	}
}int main(){
	scanf("%d%d%d",&k,&n,&m);
	for(int i = 0; i < n; i++)scanf("%d",&candidate[i]);
	rec(0,0,0);
	printf("%d\n",count);
}
