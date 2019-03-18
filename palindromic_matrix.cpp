#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,count[1001]={0},tmp;
	scanf("%d",&n);
	for(int i=0;i<n*n;i++){
		scanf("%d",&tmp);
		count[tmp]++;
		if(n==1){
			printf("YES\n%d\n",tmp);
			exit(0);
		}
	}
	if(n%2==0){
		for(int i=0;i<1001;i++){
			if(count[i]%4!=0){
				printf("NO\n");
				exit(0);
			}
		}
	}else{
		int err=0;
		for(int i=0;i<1001;i++){
			if(count[i]%4!=0&&count[i]%4==1)err++;
			else if(count[i]%4!=0){
				printf("NO\n");
				exit(0);
			}
			if(err>1){
				printf("NO\n");
				exit(0);
			}
		}
	}
	int map[1001][1001]={0},r=0,c=0;
	for(int i=0;i<1001;i++){
		while(count[i]>1){
			if(!map[r][c]){
				map[r][c]=i;
				map[n-r-1][c]=i;
				if(n-c-1==c){ 
					map[c][r]=i;
					map[c][n-r-1]=i;
				}
				else{ 
					map[r][n-c-1]=i;
					map[n-r-1][n-c-1]=i;
				}
				count[i]-=4;
				c++;
			}else{
				r++;
				c=0;
			}
		}
		if(count[i]==1)map[(n)/2][(n)/2]=i;
	}
	printf("YES\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d%c",map[i][j]," \n"[j==n-1]);
		}
	}
}
