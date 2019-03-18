#include<stdio.h>
#include<string.h>
#include<ctype.h>
int alp[40]={0},word[40],count=0,stop=0;
char in1[15],in2[15],in3[15];
int build(char *s1){
	int num=0;
	while(strlen(s1)>0){
		num*=10;
		if(isdigit(s1[0]))num+=s1[0]-'0';
		else num+=alp[s1[0]-'A'];
		s1+=1;
	}return num;
}
void try(int index){
	if(stop)return;
	if(index>=count)return;
	for(int j=1;j<=9;j++){
		alp[word[index]]=j;
		int a=build(in1),b=build(in2),c=build(in3);
		if(a*b==c){
			printf("%d x %d = %d\n",a,b,c);
			stop=1;
			return;
		}try(index+1);
	}
}
int main(){
	scanf("%s%s%s",in1,in2,in3);
	int l1=strlen(in1),l2=strlen(in2),l3=strlen(in3);
	for(int i=0;i<l1;i++){
		if(isalpha(in1[i])){
			if(!alp[in1[i]-'A']){
				alp[in1[i]-'A']=1;
				word[count++]=in1[i]-'A';
			}
		}
	}for(int i=0;i<l2;i++){
		if(isalpha(in2[i])){
			if(!alp[in2[i]-'A']){
				alp[in2[i]-'A']=1;
				word[count++]=in2[i]-'A';
			}
		}
	}for(int i=0;i<l3;i++){
		if(isalpha(in3[i])){
			if(!alp[in3[i]-'A']){
				alp[in3[i]-'A']=1;
				word[count++]=in3[i]-'A';
			}
		}
	}if(!count)printf("%s x %s = %s\n",in1,in2,in3);
	else try(0);
}
