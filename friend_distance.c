#include<stdio.h>
int relation[15][15]={0},n,m,seq[15];
int check(int now){
	for(int i=0;i<now-1;i++){
//		printf("seq %d %d\n",i,seq[i]);
		if(relation[seq[now-1]][seq[i]]==1){
//			printf("%d\n",now-i-1);
			return now-i-1;
		}
	}
	return 0;
}
int Max=100000000,s[15],used[15]={0};
void rec(int now,int max){
	int tmp=check(now),k;
//	printf("%d %d\n",now,tmp);
	if(tmp>max)k=tmp;
	else k=max;
	if(k>Max)return;
	if(now==n){
	//int tmp=check(now);
		//for(int i=0;i<n;i++)printf("%d ",seq[i]);
		//puts("");
		if(k<Max){
			Max=k;
			for(int i=0;i<n;i++)s[i]=seq[i];
		}
		return;
	}for(int i=0;i<n;i++){
		if(used[i]==0){
			used[i]=1;
			seq[now]=i;
			rec(now+1,k);
			used[i]=0;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	char in[2][2];
	for(int i=0;i<m;i++){
		scanf("%s%s",in[0],in[1]);
		relation[in[0][0]-'A'][in[1][0]-'A']=1;
		relation[in[1][0]-'A'][in[0][0]-'A']=1;
	}
//	printf("%d %d %d %d\n",relation[0][1],relation[0][2],relation[1][0],relation[1][3]);
	rec(0,0);
	printf("%d\n",Max);
	for(int i=0;i<n;i++){
		printf("%c%c",s[i]+'A'," \n"[i==n-1]);
	}
}
