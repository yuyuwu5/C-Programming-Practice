#include<bits/stdc++.h>
using namespace std;
int inside(int p_r,int p_c,int r,int c){ 
	return p_r<r&&p_r>=0&&p_c<c&&p_c>=0;
}
int safe(int map[105][105],int must[105][105],int p_r,int p_c,int r,int c){
	int select[4]={0};
	if(inside(p_r-1,p_c,r,c)){ 
		if(must[p_r-1][p_c]){
			select[0]=1;
		}
	}else select[0]=1;
	if(inside(p_r+1,p_c,r,c)){ 
		if(must[p_r+1][p_c]){
			select[2]=1;
		}
	}else select[2]=1;
	if(inside(p_r,p_c-1,r,c)){ 
		if(must[p_r][p_c-1]){
			select[3]=1;
		}
	}else select[3]=1;
	if(inside(p_r,p_c+1,r,c)){ 
		if(must[p_r][p_c+1]){
			select[1]=1;
		}
	}else select[1]=1;
	for(int i=0;i<4;i++){
		if(select[i]==0){
			map[p_r][p_c]=i+1;
			return 1;
		}
	}return 0;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		int r,c,k,total,map[105][105]={0},must[105][105]={0};//1 for north,2 for east,3 for south,4 for west
		scanf("%d%d%d",&r,&c,&k);
		total=r*c;
		int p_r=0,p_c=0;
/*		if(total-k==1){
			printf("Case #%d: IMPOSSIBLE\n",i+1);
			continue;
		}*/
		if(k>0){
			must[p_r][p_c]=1;
			map[p_r][p_c++]=1;
			k--;
		}
		while(k>0){
			if(p_c==c){
				p_r++;
				p_c=0;
				must[p_r][p_c]=1;
				map[p_r][p_c++]=1;
			}else{
				must[p_r][p_c]=1;
				map[p_r][p_c++]=4;
			}k--;
		}
		int stop=0;
		for(int j=p_c;j<c;j++){ 
			if(!safe(map,must,p_r,j,r,c)){
				printf("Case #%d: IMPOSSIBLE\n",i+1);
				stop=1;
				break;
			}
		}
		for(int j=p_r+1;j<r;j++){
			for(int l=0;l<c;l++){
				if(!safe(map,must,j,l,r,c)){
					printf("Case #%d: IMPOSSIBLE\n",i+1);
					stop=1;
					break;
				}
			}
		}
		if(stop)continue;
		printf("Case #%d: POSSIBLE\n",i+1);
		for(int j=0;j<r;j++){
			for(int l=0;l<c;l++){
				if(map[j][l]==1)printf("N");
				else if(map[j][l]==2)printf("E");
				else if(map[j][l]==3)printf("S");
				else if(map[j][l]==4)printf("W");
				else printf("W");
			}printf("\n");
		}
	}
}
