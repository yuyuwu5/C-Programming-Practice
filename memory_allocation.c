#include<stdio.h>
#include<stdlib.h>
typedef struct Memory{
	int start,length,end;
	struct Memory *next,*pre;
}Memory;
void initMemory(Memory *memory, int length){
	Memory *new=(Memory*)malloc(sizeof(Memory));
	new->start=0;
	new->length=length;
	new->end=length;
	new->next=NULL;
	new->pre=memory;
	memory->start=-1;
	memory->end=-1;
	memory->length=-1;
	memory->next=new;
	memory->pre=NULL;
}void printMemory(Memory *memory){
	printf("==========\n");
	Memory *tmp=memory->next;
	while(tmp){
		printf("start %d, length %d\n",tmp->start,tmp->length);
		tmp=tmp->next;
	}
}void allocateMemory(Memory *memory, int start, int length){
	Memory *tmp=memory;
	while(tmp){
		if(tmp->start<=start&&tmp->end>=start+length)break;
		else tmp=tmp->next;
	}if(tmp->start==start&&tmp->end==start+length){
		if(tmp->pre)tmp->pre->next=tmp->next;
		if(tmp->next)tmp->next->pre=tmp->pre;
		//free(tmp);
		return;
	}if(tmp->start==start){
		tmp->start=start+length;
		tmp->length=tmp->end-tmp->start;
		return;
	}if(tmp->end==start+length){
		tmp->end=start;
		tmp->length=tmp->end-tmp->start;
		return;
	}Memory *new=(Memory*)malloc(sizeof(Memory));
	new->start=start+length;
	new->end=tmp->end;
	new->length=new->end-new->start;
	new->next=tmp->next;
	if(tmp->next)tmp->next->pre=new;
	new->pre=tmp;
	tmp->next=new;
	tmp->end=start;
	tmp->length=tmp->end-tmp->start;
}
void freeMemory(Memory *memory, int start, int length){
	Memory *tmp1=memory,*tmp2=memory->next;
	if(start<tmp1->start){
		if(start+length==tmp1->start){
			tmp1->start=start;
			tmp1->length+=length;
			return;
		}Memory *new=(Memory*)malloc(sizeof(Memory));
		new->start=start;
		new->end=start+length;
		new->length=length;
		new->pre=NULL;
		new->next=tmp1;
		tmp1->pre=new;
		return;
	}while(tmp1&&tmp2){
		if(tmp1->start<=start&&start<tmp2->start)break;
		else{
			tmp1=tmp1->next;
			tmp2=tmp2->next;
		}
	}if(!tmp2){
		if(tmp1->end==start){
			tmp1->end+=length;
			tmp1->length+=length;
			return;
		}Memory *new=(Memory*)malloc(sizeof(Memory));
		new->start=start;
		new->length=length;
		new->end=start+length;
		new->next=NULL;
		new->pre=tmp1;
		tmp1->next=new;
		return;
	}if(start==tmp1->end&&start+length==tmp2->start){
		tmp1->end=tmp2->end;
		tmp1->length=tmp1->end-tmp1->start;
		if(tmp2->next)tmp2->next->pre=tmp1;
		tmp1->next=tmp2->next;
		free(tmp2);
		return;
	}if(start==tmp1->end){
		tmp1->end=start+length;
		tmp1->length+=length;
		return;
	}if(start+length==tmp2->start){
		tmp2->start=start;
		tmp2->length+=length;
		return;
	}Memory *new=(Memory*)malloc(sizeof(Memory));
	new->start=start;
	new->end=start+length;
	new->length=length;
	tmp1->next=new;
	new->pre=tmp1;
	tmp2->pre=new;
	new->next=tmp2;
}
int main() {
	char c[5];
	Memory myMemory;
	while(scanf("%s",c)!=EOF){
		int a,b;
		if(c[0]=='I'){
			scanf("%d",&a);
			scanf("%d",&a);
			initMemory(&myMemory, a);
		}else if(c[0]=='A'){
			scanf("%d",&a);
			scanf("%d%d",&a,&b);
			allocateMemory(&myMemory, a, b);
		}else if(c[0]=='P'){
			scanf("%d",&a);
			printMemory(&myMemory);
		}else if(c[0]=='F'){
			scanf("%d",&a);
			scanf("%d%d",&a,&b);
			freeMemory(&myMemory, a, b);
		}
	}
}
