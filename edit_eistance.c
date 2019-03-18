#include<stdio.h>
#include<string.h>
int distance(char *s1,char *s2,int l_s1,int l_s2){
	if(!l_s1&&!l_s2)return 0;
	if(!l_s1)return strlen(s2);
	if(!l_s2)return strlen(s1);
	if(s1[0]==s2[0])return distance(s1+1,s2+1,l_s1-1,l_s2-1);
	int a=distance(s1+1,s2,l_s1-1,l_s2),b=distance(s1,s2+1,l_s1,l_s2-1);
	if(a<b)return 1+a;
	else return 1+b;
}int main(){
	char in[105][15],index=1;
	char *p[105];
	while(scanf("%s",in[index])!=EOF){
			p[index]=in[index];
			index++;
	}int id1,id2,min=10000000;
	for(int i=1;i<index;i++){
		for(int j=i+1;j<index;j++){
			int k=distance(p[i],p[j],strlen(p[i]),strlen(p[j]));
			if(min>k){
				min=k;
				id1=i;
				id2=j;
			}
		}
	}printf("%d %d %d\n",min,id1,id2);
}
