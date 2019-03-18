#include<stdio.h>
int map[1000][1000]={0};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int temp_x[100000],temp_y[100000],count=0,x=0,y=0;;
		for(int j=x1;j<=x2;j++)
			for(int k=y1;k<=y2;k++){
				if(map[k][j]==0){temp_y[y++]=k;temp_x[x++]=j;count++;map[k][j]=1;}
			}
		printf("%d", count);
		if(count>0)printf(" ");
		for(int j=0;j<count;j++){
			printf("(%d, %d)",temp_x[j],temp_y[j]);
			if(j!=count-1)printf(" ");
		}
		printf("\n");
	}
}