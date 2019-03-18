#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int id,chinese,english,math,science,social,total;
}Student;
Student s[20000];
int cmp(const void *p1,const void *p2){
	Student *s1=(Student*)p1,*s2=(Student*)p2;
	if(s1->total<s2->total)return 1;
	if(s1->total>s2->total)return -1;
	if(s1->math<s2->math)return 1;
	if(s1->math>s2->math)return -1;
	if(s1->english<s2->english)return 1;
	if(s1->english>s2->english)return -1;
	if(s1->science<s2->science)return 1;
	if(s1->science>s2->science)return -1;
	if(s1->chinese<s2->chinese)return 1;
	if(s1->chinese>s2->chinese)return -1;
	if(s1->social<s2->social)return 1;
	if(s1->social>s2->social)return -1;
	return 0;
}
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d%d%d",&s[i].id,&s[i].chinese,&s[i].english,&s[i].math,&s[i].science,&s[i].social);
		s[i].total=s[i].chinese+s[i].english+s[i].math+s[i].science+s[i].social;
	}qsort(s,n,sizeof(Student),cmp);
	for(int i=0;i<m;i++)printf("%d\n",s[i].id);
	int now=m;
	while(1){
		if(s[now].total==s[m-1].total&&
			s[now].chinese==s[m-1].chinese&&
			s[now].math==s[m-1].math&&
			s[now].science==s[m-1].science&&
			s[now].social==s[m-1].social&&
			s[now].english==s[m-1].english){
				printf("%d\n",s[now].id);
				now++;
		}else break;
	}
}
