#include<stdio.h>
int q[15];
void derangement(int people,int rule,int person[],int pos[],int process){
	int used[11]={0};
	if(process>people){
		for(int i=0;i<people;i++)printf("%c",q[i]+64);
		printf("\n");
		return;
	}for(int i=0;i<process-1;i++)used[q[i]]=1;
	for(int i=0;i<rule;i++)if(pos[i]==process)used[person[i]]=1;
	for(int i=1;i<=people;i++){
		if(!used[i]){
			q[process-1]=i;
			derangement(people,rule,person,pos,process+1);
		}
	}
}
int main(){
	int people;
	while(scanf("%d",&people)!=EOF){
		int rule;
		scanf("%d",&rule);
		int person[105],pos[105];
		for(int i=0;i<rule;i++){
			scanf("%d%d",&person[i],&pos[i]);
		}derangement(people,rule,person,pos,1);
	}
}
