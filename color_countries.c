#include<stdio.h>
typedef struct country{
	int color[9],adjacent[20],neighbor,final,avail_color;
}country;
country city[20];
int n,c,p,fail=0;
void coloring(int index){
	if(index>=n)return;
	if(fail)return;
	if(city[index].final)return;
	if(city[index].avail_color<=0){
		fail=1;
		return;
	}for(int j=1;j<=c;j++){
		if(city[index].color[j]==1){
			city[index].final=j;
			for(int i=0;i<n;i++){
				if(city[index].adjacent[i]){
					city[i].color[j]=0;
					city[i].neighbor--;
					city[i].avail_color--;
				}
			}break;
		}
	}int min=n-1,kk=0;
	for(int i=0;i<n;i++){
		if(!city[i].final){
			if(min>city[i].neighbor){
				min=city[i].neighbor;
				kk=i;
			}
		}
	}if(city[kk].final)return;
	coloring(kk);
}
int main(){
	scanf("%d%d%d",&n,&c,&p);
	for(int i=0;i<n;i++){
		for(int j=1;j<=c;j++)city[i].color[j]=1;
		for(int j=0;j<n;j++)city[i].adjacent[j]=0;
		city[i].neighbor=city[i].final=0;
		city[i].avail_color=c;
	}for(int i=0;i<p;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		city[a].adjacent[b]=1;
		city[a].neighbor++;
		city[b].adjacent[a]=1;
		city[b].neighbor++;
	}coloring(0);
	/*if(!fail)*/for(int i=0;i<n;i++)printf("%d\n",city[i].final);
	//else printf("no solution\n");
}
