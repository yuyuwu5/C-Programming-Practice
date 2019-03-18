#include<stdio.h>
int main(){
	int n,m,iden[20][20]={0};
	scanf("%d%d",&n,&m);
	int t=2*m*m;	
	for(int i=0;i<m;i++)for(int j=0;j<m;j++)iden[i][j]=1;
	for(int i=0;i<n;i++){
		int type,in[20][20];
		scanf("%d",&type);
		for(int j=0;j<m;j++)for(int k=0;k<m;k++)scanf("%d",&in[j][k]);
		int sum=0;
		for(int j=0;j<m;j++)for(int k=0;k<m;k++)sum+=iden[j][k]*in[j][k];
		if(type==0){
			if(sum>=t){
				for(int j=0;j<m;j++){
					for(int k=0;k<m;k++){
						if(in[j][k]==1){
							iden[j][k]/=2;
							if(iden[j][k]==0)iden[j][k]=1;
						}
					}
				}
			}
		}else if(type==1){
			if(sum<t){
				for(int j=0;j<m;j++){
					for(int k=0;k<m;k++){
						if(in[j][k]==1){
							iden[j][k]*=2;
						}
					}
				}
			}
		}
	}int input,h=0;
	scanf("%d",&input);
	for(int i=0;i<input;i++){
		int in[20][20],sum=0;
		for(int j=0;j<m;j++){
			for(int k=0;k<m;k++){
				scanf("%d",&in[j][k]);
				sum+=in[j][k]*iden[j][k];
			}
		}if(sum>=t)puts("1");
		else puts("0");
	}
}

			
