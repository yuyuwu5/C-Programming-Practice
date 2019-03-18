#include<stdio.h>
int max=-1,start,end=-1,l;
void length(int in){
	int run=0;
	l=0;
	while(in){
		start=in;
		l++;
		if(!run){
			end=in%10;
			run=1;
		}in/=10;
	}
}
int main(){
	int in,now=0,pre;
	while(scanf("%d",&in)!=EOF){
		pre=end;
		length(in);
		if(pre==start){
			now+=l;
		}else now=l;
		if(max<now)max=now;
	}printf("%d\n",max);
}

