#include<stdio.h>
#include<ctype.h>
#include<string.h>
typedef struct val{
	char word[35];
	int value;
}val;
typedef struct s{
	int data;
	int symbol;
}s;
int main(){
	char express[1000];
	fgets(express,1000,stdin);
	int l=strlen(express),now=0,k=0;
	val x[50];
	s stack[1000];
	for(int i=0;i<1000;i++)stack[i].symbol=0;
	char in_a[1000],in_b[3],in_c[1000];
	while(scanf("%s%s%s",in_a,in_b,in_c)!=EOF){
		strcpy(x[k].word,in_a);
		int ll=strlen(in_c),num=0;
		for(int i=0;i<ll;i++){
			num*=10;
			num+=in_c[i]-'0';
		}x[k++].value=num;
	}for(int i=0;i<l;i++){
		if(express[i]==' ')continue;
		else if(express[i]=='(')stack[now++].data=-10;
		else if(express[i]==')'){
			int t,a,b;/*
			if(stack[now-2].symbol==1){
				a=x[stack[now-2].data+100].value;
			}else*/ a=stack[now-2].data;
			/*if(stack[now-1].symbol==1){
				b=x[stack[now-1].data+100].value;
			}else*/ b=stack[now-1].data;
			if(stack[now-3].symbol==-1)t=a+b;	
			else if(stack[now-3].symbol==-2)t=a-b;
			else if(stack[now-3].symbol==-3)t=a*b;
			else if(stack[now-3].symbol==-4)t=a/b;
			stack[now-1].data=stack[now-2].data=stack[now-3].data=0;
			stack[now-4].data=t;
			now-=3;
		}else if(express[i]=='+')stack[now++].symbol=-1;
		else if(express[i]=='-')stack[now++].symbol=-2;
		else if(express[i]=='*')stack[now++].symbol=-3;
		else if(express[i]=='/')stack[now++].symbol=-4;
		else if(isdigit(express[i])){
				int num=0;
				while(isdigit(express[i])){
					num*=10;
					num+=express[i++]-'0';
				}stack[now++].data=num;
		}else{
			char tmp[35];
			int count=0;
			while(express[i]!=' ')tmp[count++]=express[i++];
			tmp[count]='\0';
			int j;
			for(j=0;j<k;j++)if(strcmp(x[j].word,tmp)==0)break;
			stack[now++].data=x[j].value;
		}
	}printf("%d\n",stack[0].data);
}
