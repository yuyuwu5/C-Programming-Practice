#include<bits/stdc++.h>
using namespace std;
int find_legal(int in[1005],int start,int end){
	int s=in[start],star=start+1,middle=in[start+1];
	while(s==middle)middle=in[++star];
	if(s>middle){
		for(int i=star+1;i<=end;i++){
			if(in[i]>middle){
				return 1+find_legal(in,i,end);
			}else{
				middle=in[i];
			}
		}
	}else if(s<middle){
		for(int i=star+1;i<=end;i++){
			if(in[i]<middle){
				return 1+find_legal(in,i,end);
			}else{
				middle=in[i];
			}
		}
	}return 0;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		int k,in[1005];
		scanf("%d",&k);
		for(int j=0;j<=k;j++){
			scanf("%d",&in[j]);
		}
		int legal=0;
		legal+=find_legal(in,0,k);
		printf("Case #%d: %d\n",i+1,legal-1);
	}	
}
