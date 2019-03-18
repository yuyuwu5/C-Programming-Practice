#include<stdio.h>
#include<string.h>
int n,l,r;
char name[50][l];
int distance(int a,int b){
	int sum=0;
	for(int i=0;i<l;i++)sum+=Abs(name[a][i]-name[b][i]);
	return sum;
}
int main(){
	scanf("%d%d%d",&n,&l,%r);
	int leader[3]={0,1,2};
	for(int i=0;i<l;i++)scanf("%s",name[i]);
	for(int i=0;i<r;i++){
		int group[3][50]={0},distance[3][50]={0},now[3]={1,1,1},sum[3]={0};
		group[0][0]=leader[0];
		group[1][0]=leader[1];
		group[2][0]=leader[2];
		for(int j=0;j<n;j++){
			if(j!=leader[0]&&j!=leader[1]&&j!=leader[2]){
				int min=10000000,a,choose;
				a=distance(j,leader[0]);
				if(min<a){
					choose=0;
					min=a;
				}a=distance(j,leader[1]);
				if(min<=a){
					if(min==a){
						if(strcmp(name[leader[1]],name[choose])<0){
							choose=1;
						}
					}else{
						choose=1;
						min=a;
					}
				}
				a=distance(j,leader[2]);
				if(min<=a){
					if(min==a){
						if(strcmp(name[leader[2]],name[choose])<0){
							choose=2;
						}
					}else{
						choose=1;
						min=a;
					}
				}group[choose][now[choose]]=j;
				distance[choose][now[choose]++]=min;
				sum[choose]+=min;
			}for(int j=0;j<3;j++){
				int mid=sum[j]/now[choose];
			}
		}
	}
}
