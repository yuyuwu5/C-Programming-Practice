#include<stdio.h>
#include<stdlib.h>
typedef struct account {
    int balance;
    int accountNum;
    int zipcode;
    int age;
} Account;
int cmp(const void *p1,const void *p2){
	Account *s1=(Account*)p1,*s2=(Account*)p2;
	if(s1->accountNum<s2->accountNum)return -1;
	else return 1;
}
int cmp1(const void *p1,const void *p2){
	Account *s1=(Account*)p1,*s2=(Account*)p2;
	if(s1->zipcode<s2->zipcode)return -1;
	else return 1;
}
int cmp2(const void *p1,const void *p2){
	Account *s1=(Account*)p1,*s2=(Account*)p2;
	if(s1->age<s2->age)return -1;
	else return 1;
}
int main(){
	char name[1000];
	scanf("%s",name);
	FILE *f1=fopen(name,"rb");
	Account out[100000],in[100000],a;
	puts("account, age, zipcode, balance");
	int now=0,n=0;
	while(!feof(f1)){
		fread(&in[n],sizeof(Account),1,f1);
		if(feof(f1))break;
		int find=0;
#if SORTBY == ZIPCODE
		for(int i=0;i<now;i++){
			if(out[i].zipcode==in[n].zipcode){
				out[i].balance+=in[n].balance;
				find=1;
				break;
			}
		}if(!find){
			out[now].zipcode=in[n].zipcode;
			out[now++].balance+=in[n].balance;
		}
#endif
#if SORTBY == AGE
		for(int i=0;i<now;i++){
			if(out[i].age==in[n].age){
				out[i].balance+=in[n].balance;
				find=1;
				break;
			}
		}if(!find){
			out[now].age=in[n].age;
			out[now++].balance+=in[n].balance;
		}
#endif
		n++;
	}fclose(f1);
	qsort(in,n,sizeof(Account),cmp);
	for(int i=0;i<n;i++)printf("%d, %d, %d, %d\n",in[i].accountNum,in[i].age,in[i].zipcode,in[i].balance);
#if SORTBY == ZIPCODE
		qsort(out,now,sizeof(Account),cmp1);
		puts("zipcode, sum_balance");
		for(int i=0;i<now;i++)printf("%d, %d\n",out[i].zipcode,out[i].balance);
#endif
#if SORTBY == AGE
		qsort(out,now,sizeof(Account),cmp2);
		puts("age, sum_balance");
		for(int i=0;i<now;i++)printf("%d, %d\n",out[i].age,out[i].balance);
#endif
}
