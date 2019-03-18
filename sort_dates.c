#include<stdio.h>
#include<stdlib.h>
typedef struct cal{
	int year;
	int month;
	int date;
}cal;
cal in[1000000];
int compare(const void *ptr1,const void *ptr2){
	cal *s1=(cal *)ptr1,*s2=(cal *)ptr2;
	if(s1->year<s2->year)return -1;
	if(s1->year>s2->year)return 1;
	if(s1->month<s2->month)return -1;
	if(s1->month>s2->month)return 1;
	if(s1->date<s2->date)return -1;
	if(s1->date>s2->date)return 1;
}int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i<n;i++){
		scanf("%d%d%d",&in[i].year,&in[i].month,&in[i].date);
	}qsort(in,n,sizeof(cal),compare);
	for(int i = 0; i < n; i++){
		printf("%d %d %d\n",in[i].year,in[i].month,in[i].date);
	}
}

