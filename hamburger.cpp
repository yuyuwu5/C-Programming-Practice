#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,burger[200]={0},List[200]={0},out[200]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&m);
		for(int j=0;j<m/2;j++){
			List[j]=j;
			List[m-1-j]=j;
		}
		if(m%2==1)List[m/2]=m/2;
		for(int j=0;j<m;j++){
			scanf("%d",&burger[j]);
		}
		sort(burger,burger+m);		
		/*
		for(int j=0;j<m;j++){
			printf("%d\n",List[j]);
		}
		*/
		int start=0,end=m-1,error=0;
		for(int j=0;j<m;j++){
			if(j%2){
				out[end--]=burger[j];
			}else{
				out[start++]=burger[j];
			}
		}
		for(int j=0;j<m;j++){
			error+=(out[j]-List[j])*(out[j]-List[j]);
		}
		printf("Case #%d: %d\n",i+1,error);
	}
}
