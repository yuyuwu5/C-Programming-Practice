#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char name[17];
	long long cite;
}scholar;
scholar s[20000];
int cmp(const void *p1,const void *p2){
	scholar *s1=(scholar*)p1,*s2=(scholar*)p2;
	int k=strcmp(s1->name,s2->name);
	if(k!=0)return k;
	if(s1->cite<s2->cite)return 1;
	if(s1->cite>s2->cite)return -1;
	return 0;
}void check(int left,int right){
	int total=right-left+1,now=0;
	for(int i=left;i<=right;i++){
		if(s[i].cite>=now+1){
			now++;
		}else{
			printf("%s %d\n",s[i].name,now);
			return;
		}
	}printf("%s %d\n",s[right].name,now);
}int main(){
	int c=0;
	while(scanf("%s%lld",s[c].name,&s[c].cite)!=EOF)c++;
	qsort(s,c,sizeof(scholar),cmp);
	char name[17];
	int left=0,right=0;
	strcpy(name,s[0].name);
	for(int i=0;i<c;i++){
		if(strcmp(name,s[i].name)==0){
			if(i>0)right++;
		}else{
			check(left,right);
			strcpy(name,s[i].name);
			left=right=i;
		}
	}check(left,right);
}
