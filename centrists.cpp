#include<bits/stdc++.h>
int seq[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
void check(char in[3][150],int l,int out[3]){
	for(int i=0;i<6;i++){
		int alpha[26]={0},level=100,err=0;
		for(int k=0;k<2;k++){
			for(int j=0;j<l;j++){
				if(in[seq[i][k]][j]!=in[seq[i][k+1]][j]){
					if(alpha[in[seq[i][k]][j]-'A']==0&&alpha[in[seq[i][k+1]][j]-'A']==0){
						alpha[in[seq[i][k]][j]-'A']=level--;
						alpha[in[seq[i][k+1]][j]-'A']=level--;
					}else if(alpha[in[seq[i][k]][j]-'A']!=0&&alpha[in[seq[i][k+1]][j]-'A']==0){
						alpha[in[seq[i][k+1]][j]-'A']=level--;
					}else if(alpha[in[seq[i][k]][j]-'A']==0&&alpha[in[seq[i][k+1]][j]-'A']!=0){
						alpha[in[seq[i][k]][j]-'A']=level+101;
					}else{
						if(alpha[in[seq[i][k]][j]-'A']<=alpha[in[seq[i][k+1]][j]-'A']){
							err=1;
						}
					}break;
				}
			}
		}
		if(!err)out[seq[i][1]]=1;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int l,out[3]={0};
		scanf("%d",&l);
		char in[3][150]={0};
		for(int j=0;j<3;j++)scanf("%s",in[j]);
		check(in,l,out);
		printf("Case #%d:",i+1);
		for(int i=0;i<3;i++){ 
			if(out[i])printf(" YES");
			else printf(" NO");
		}printf("\n");
	}
}
