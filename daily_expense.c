#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct need{
	int year,month,date,money;
	char reason[35];
}need;
need in[10005];
int i = 0;
int compare(const void *ptr1,const void *ptr2){
	need *s1=(need *)ptr1,*s2=(need *)ptr2;
	if(s1->year<s2->year)return -1;
	if(s1->year>s2->year)return 1;
	if(s1->month<s2->month)return -1;
	if(s1->month>s2->month)return 1;
	if(s1->date<s2->date)return -1;
	if(s1->date>s2->date)return 1;
	if(strcmp(s1->reason,s2->reason)<0)return -1;
	if(strcmp(s1->reason,s2->reason)>0)return 1;
	s1->money+=s2->money;
	s2->year=-1;
}int main(){
	while(scanf("%d%d%d%s%d",&in[i].year,&in[i].month,&in[i].date,in[i].reason,&in[i].money)!=EOF){
		i++;
	}qsort(in,i,sizeof(need),compare);
	for(int j = 0; j < i; j++){
		if(in[j].year>0){
			printf("%d %d %d %s %d\n",in[j].year,in[j].month,in[j].date,in[j].reason,in[j].money);
		}
	}
}
