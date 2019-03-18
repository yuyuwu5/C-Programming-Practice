#include<stdio.h>
#include<stdlib.h>
typedef struct city{
	int neighbor,walk,count,data,link[1001];
}city;
city c[1001];
int out[1001];
void go(int index,int n,int count){
	if(count>=n)return;
	out[count]=index;
	c[index].walk=1;
	for(int i=0;i<c[index].count;i++){
		if(!c[c[index].link[i]].walk){
			go(c[index].link[i],n,count+1);		
		}
	}if(count+1==n){
		if(c[index].link[0]==0){
			for(int i=0;i<n;i++)printf("%d ",out[i]);
			printf("0\n");
			exit(0);
		}
	}c[index].walk=0;
}int cmp(const void *p1,const void *p2){
	int *s1=(int*)p1,*s2=(int*)p2;
	if(*s1<*s2)return -1;
	if(*s1>*s2)return 1;
	return 0;
}int main(){
	int n,e;
	scanf("%d%d",&n,&e);
	for(int i=0;i<n;i++){
		c[i].count=c[i].walk=0;
		c[i].data=i;
	}for(int i=0;i<e;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		c[a].link[c[a].count++]=b;
		c[b].link[c[b].count++]=a;
	}for(int i=0;i<n;i++)qsort(c[i].link,c[i].count,sizeof(int),cmp);
	go(0,n,0);
	printf("NO SOLUTION\n");
}
