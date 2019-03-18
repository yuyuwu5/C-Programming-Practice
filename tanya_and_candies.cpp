#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int input[200001];
	long long add1[200001],add2[200001];
	for(int i=0;i<n;i++){
		scanf("%d",&input[i]);
		if(i-2>=0)add1[i]=add1[i-2]+input[i];
		else add1[i]=input[i];
	}
	for(int i=n-1;i>=0;i--){
		if(i+2<n)add2[i]=add2[i+2]+input[i];
		else add2[i]=input[i];
	}
	int get=0;
	for(int i=0;i<n;i++){
		int a=0,b=0,c=0,d=0;
		if(i-2>=0)a=add1[i-2];
		if(i-1>=0)b=add1[i-1];
		if(i+1<n)c=add2[i+1];
		if(i+2<n)d=add2[i+2];
		if(a+c==b+d)get++;
	}
	printf("%d\n",get);
}
