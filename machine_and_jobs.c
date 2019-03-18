#include<stdio.h>
#include<stdlib.h>
typedef struct job{
	int arrive,time,mac,done;
	struct job *next;
}job;
typedef struct machine{
	int timer,expect,target;
}machine;
int main(){
	int n,m,total=0;
	job *jobs[505];
	machine machines[505];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		machines[i].target=-1;
		machines[i].timer=0;
	}for(int i=0;i<m;i++){
		int arrive,todo;
		scanf("%d%d",&arrive,&todo);
		total+=todo;
		job *move=NULL;
		for(int j=0;j<todo;j++){
			job *tmp=(job*)malloc(sizeof(job));
			tmp->done=0;
			tmp->next=NULL;
			tmp->arrive=-1;
			scanf("%d%d",&tmp->mac,&tmp->time);
			if(!move){
				tmp->arrive=arrive;
				jobs[i]=tmp;
			}else move->next=tmp;
			move=tmp;
		}
	}while(total){
		int min=1000000,index;
		for(int i=0;i<m;i++){
			if(jobs[i]->done)continue;
			int tmp=jobs[i]->arrive;
			if(tmp<machines[jobs[i]->mac].timer)tmp=machines[jobs[i]->mac].timer;
			tmp+=jobs[i]->time;
			if(tmp<min){
				min=tmp;
				index=i;
			}
		}machines[jobs[index]->mac].timer=min;
		if(jobs[index]->next){
			jobs[index]=jobs[index]->next;
			jobs[index]->arrive=min;
		}else{
			jobs[index]->time=min;
			jobs[index]->done=1;
		}total--;
	}for(int i=0;i<m;i++)printf("%d\n",jobs[i]->time);
}
