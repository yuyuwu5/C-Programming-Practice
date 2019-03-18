#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
char in[10000][100]={0},c;
void check(int count){
	int now=0;
	float stack[10000];
	for(int i=0;i<count;i++){
		if(in[i][0]=='('){
			stack[now++]=-1;
			stack[now++]=atof(&in[i][1]);
		}else if(in[i][strlen(in[i])-1]==')'){
			int j;
			for(j=0;j<strlen(in[i]);j++)if(in[i][j]==')')break;
			if(in[i][0]!=')'){
				stack[now++]=atof(in[i]);
			}while(j<strlen(in[i])){
				float cc=stack[now-3]*(stack[now-2]+stack[now-1])+(1-stack[now-3])*(stack[now-2]-stack[now-1]);
				stack[now-4]=cc;
				now-=3;
				j++;
			}
			
		}else stack[now++]=atof(in[i]);
	}printf("%.2f\n",stack[0]);
}int main(){
	char tmp[10000];
	while(fgets(tmp,10000,stdin)!=0){
		int l=strlen(tmp),now=0,start=0;
		for(int i=0;i<l;i++){
			if(tmp[i]!=' '&&tmp[i]!='\n'&&tmp[i]!='\0'&&tmp[i]!='\r')in[now][i-start]=tmp[i];
			else {
				in[now][i-start]='\0';
				now++;
				start=i+1;
			}
		}now++;
		check(now);
	}
}
