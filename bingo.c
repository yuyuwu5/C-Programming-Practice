#include<stdio.h>
int xx[10][300]={{0}},yy[10][300]={{0}},xy[10]={0},yx[10]={0},player,n,x[10][66000],y[10][66000],hash[600000]={0};
char name[10][65];
int check(int in){
	int p=0,get=0;
	for(int i = 0; i < player; i++){
		xx[i][x[i][hash[in]]]++;
		yy[i][y[i][hash[in]]]++;
		if(x[i][hash[in]]==y[i][hash[in]])xy[i]++;
	       	if(n-x[i][hash[in]]-1==y[i][hash[in]])yx[i]++;
		if(xx[i][x[i][hash[in]]]==n || yy[i][y[i][hash[in]]]==n || xy[i]==n || yx[i]==n){
			if(!p){
				printf("%d",in);
				p=1;
			}printf(" %s",name[i]);
			get=1;
		}
	}return get;
}int main(){
	int tmp,now=1;
	scanf("%d%d",&player,&n);
	for(int i = 0; i < player;i++){
		scanf("%s",name[i]);
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				scanf("%d",&tmp);
				if(hash[tmp]==0){
					hash[tmp]=now++;
				}x[i][hash[tmp]]=k;
				y[i][hash[tmp]]=j;
			}
		}
	}while(scanf("%d",&tmp)!=EOF){
		if(check(tmp))return 0;
	}
}

