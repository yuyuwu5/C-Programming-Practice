#include<stdio.h>
int determine(int x,int y,int map[12][12])
{
	if(map[y][x]==0){return 0;}
	if(x==0 || y==0){return 1;}
	return determine(x,y-1,map)+determine(x-1,y,map);
}
int main()
{
	int x,y;
	scanf("%d%d",&y,&x);
	int map[12][12],obs=0;;
	for (int i = y-1; i >= 0; i--){
		for(int j = 0; j < x;j++){
			scanf("%d",&map[i][j]);
		}
	}int flag=-1;
	for(int i = 0; i < y;i++)
		if(map[i][0]==0){flag=i;break;}
	for(int i = flag;i<y && flag>0;i++)
		map[i][0]=0;
	flag=-1;
	for(int i = 0; i < x;i++)
		if(map[0][i]==0){flag=i;break;}
	for(int i = flag; i < x && flag>0; i++)
		map[0][i]=0;
	int a=determine(x-1,y-1,map);
	printf("%d",a);
}