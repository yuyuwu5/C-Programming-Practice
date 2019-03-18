#include<stdio.h>
int n,m;
void cal(char in[1025][515]){
	float all=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			float sim=0;
			for(int k=0;k<m;k++){
				if(in[i][k]==in[j][k])sim++;
			}float tmp=sim/m;
			if(tmp>0.8001){
				all++;
				printf("this %s %s\n",in[i],in[j]);
			}
		}
	}float mm=n*(n-1)/2;
	printf("%.2f\n",all/mm*100);
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		char in[1025][515];
		for(int i=0;i<n;i++)scanf("%s",in[i]);
		cal(in);
	}
}
