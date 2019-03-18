#include<stdio.h>
unsigned long long people[65]={0},clubs[101]={0};
int stack[65],stop=0,club,target;
void find(int now,unsigned long long num){
	if(stop)return;
	if(now==target){
		for(int i=0;i<target;i++)printf("%d\n",stack[i]);
		stop=1;
		return;
	}for(int i=stack[now-1];i<club;i++){
		if((num&clubs[i])==0){
			stack[now]=i;
			find(now+1,(num|clubs[i]));
		}
	}
}
int main(){
	scanf("%d%d",&club,&target);
	unsigned long long t=1;
	for(int i=0;i<64;i++){
		people[i]=t;
		t=t<<1;
	}for(int i=0;i<club;i++){
		int member;
		scanf("%d",&member);
		for(int j=0;j<member;j++){
			int id;
			scanf("%d",&id);
			clubs[i]|=people[id];
		}
	}find(0,0);
}
