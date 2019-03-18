#include<stdio.h>
int main(){
	int k,in,start=0,num=0;
	scanf("%d",&k);
	while(scanf("%d",&in)!=EOF){
		num*=10;
		num+=in;
		if(num/k>0)start=1;
		if(!start)continue;
		printf("%d\n",num/k);
		num-=(num/k)*k;
	}if(!start)puts("0");
}
		
