#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLENGTH 16
#define MAXCOMPONENT 64
typedef struct{
    char name[MAXLENGTH];
    int numComponent;
    int componentPartList[MAXCOMPONENT];
    int price;
}ComponentPart;
int cmp(const void *p1,const void *p2){
	ComponentPart *s1=(ComponentPart*)p1,*s2=(ComponentPart*)p2;
	return strcmp(s1->name,s2->name);
}void build(int N,int now,ComponentPart list[]){
	if(!list[now].numComponent||list[now].numComponent&&list[now].price)return;
	for(int i=0;i<list[now].numComponent;i++){
		if(list[list[now].componentPartList[i]].price){
			list[now].price+=list[list[now].componentPartList[i]].price;
		}else{
			build(N,list[now].componentPartList[i],list);
			list[now].price+=list[list[now].componentPartList[i]].price;
		}
	}
}
void findPrice(int N,ComponentPart list[]){
	for(int i=0;i<N;i++)build(N,i,list);
	qsort(list,N,sizeof(ComponentPart),cmp);
	for(int i=0;i<N;i++)printf("%s %d\n",list[i].name,list[i].price);
}
int main(){
    int N;
    scanf("%d",&N);
    ComponentPart list[N];
    for(int i=0;i<N;i++){
        scanf("%s%d",list[i].name,&list[i].numComponent);
        if(list[i].numComponent){
            for(int j=0;j<list[i].numComponent;j++)
                scanf("%d",&list[i].componentPartList[j]);
            list[i].price=0;
        }else scanf("%d",&list[i].price);
    }findPrice(N,list);
}
