#include<stdio.h>
#include<stdlib.h>
struct in{
	int one;
	long long data;
};
int compare(const void *ptr1,const void *ptr2){
	struct in *s1=(struct in *)ptr1;
	struct in *s2=(struct in *)ptr2;
	if(s1->one>s2->one)return 1;
	else if(s1->one<s2->one)return -1;
	else if(s1->data>s2->data)return 1;
	else return -1;
}int main(){
	long long test=1,i=0;
	struct in input[1005];
	while(scanf("%lld",&input[i].data)!=EOF){
		int count=0;
		for(int j = 0; j < 63; j++){
			if(test&input[i].data)count++;
			test=test<<1;
		}test=1;
		input[i++].one=count;
	}qsort(input,i,sizeof(struct in),compare);
	for(int j=0;j<i;j++)printf("%lld\n",input[j].data);
}
