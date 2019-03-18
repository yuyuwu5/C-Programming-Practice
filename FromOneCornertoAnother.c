#include<stdio.h>
int determine(int x,int y)
{
	if(x==0 || y==0){return 1;}
	return  determine(x,y-1)+determine(x-1,y);
}
int main()
{
	int x,y;
	scanf("%d%d",&y,&x);
	printf("%d",determine(x-1,y-1));
}