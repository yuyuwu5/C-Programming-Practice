#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	char name[64];
	int height,weight;
	float bmi;
}student;
student s[100001];
int cmp(const void *p1,const void *p2){
	student *s1=(student*)p1,*s2=(student*)p2;
	if(s1->bmi<s2->bmi)return -1;
	if(s1->bmi>s2->bmi)return 1;
	if(s1->weight<s2->weight)return -1;
	if(s1->weight>s2->weight)return 1;
	if(s1->height<s2->height)return -1;
	if(s1->height>s2->height)return 1;
	return strcmp(s1->name,s2->name);
}int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s%d%d",s[i].name,&s[i].height,&s[i].weight);
		s[i].bmi=(float)s[i].weight/(((float)s[i].height/100)*((float)s[i].height/100));
	}qsort(s,n,sizeof(student),cmp);
	for(int i=0;i<n;i++)printf("%s %d %d\n",s[i].name,s[i].height,s[i].weight);
}
