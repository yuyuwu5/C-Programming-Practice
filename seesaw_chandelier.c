#include<stdio.h>
int in[16384],out[16384]={0};
void find(int left,int center,int right){
	if(right-left<2)return;
	if(center>right)return;
	long long l=0,r=0;
	for(int i=left;i<center;i++)l+=(in[i]*(center-i));
	for(int i=center+1;i<=right;i++)r+=(in[i]*(i-center));
	if(r==l){
		out[center]=1;
		find(left,left,center-1);
		find(center+1,center+1,right);
	}else find(left,center+1,right);
}int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&in[i]);
	find(0,0,n-1);
	for(int i=0;i<16384;i++)if(out[i])printf("%d\n",i);
}
