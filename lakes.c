#include<stdio.h>
#include<stdlib.h>
int n,m,map[400][400],lake[160000],iNdex=0;
int compare(const void *p1,const void *p2){
	int *q1=(int*)p1,*q2=(int*)p2;
	if(*q1<*q2)return 1;
	if(*q1>*q2)return -1;
	return 0;
}void walk(int i,int j){
	if(map[i][j]!=1)return;
	map[i][j]=-1;
	lake[iNdex]++;
	if(i-1>=0)walk(i-1,j);
	if(i+1<n)walk(i+1,j);
	if(j-1>=0)walk(i,j-1);
	if(j+1<m)walk(i,j+1);
}void check(){
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(map[i][j]==1){
				walk(i,j);
				iNdex++;
			}
}int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)scanf("%d",&map[i][j]);
	check();
	qsort(lake,iNdex,sizeof(int),compare);
	for(int i = 0; i < iNdex; i++)printf("%d\n",lake[i]);
}
