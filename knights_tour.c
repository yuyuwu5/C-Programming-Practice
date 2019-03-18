#include<stdio.h>
int map[105][105]={0},n,m;
typedef struct{
	int y,x,live;
}Knight;
int count(int y,int x){
	int c=0;
	if(y-2>=0){
		if(x-1>=0&&map[y-2][x-1]==0)c++;
		if(x+1<n&&map[y-2][x+1]==0)c++;
	}
	if(y+2<n){
		if(x-1>=0&&map[y+2][x-1]==0)c++;
		if(x+1<n&&map[y+2][x+1]==0)c++;
	}
	if(y-1>=0){
		if(x-2>=0&&map[y-1][x-2]==0)c++;
		if(x+2<n&&map[y-1][x+2]==0)c++;
	}if(y+1<n){
		if(x-2>=0&&map[y+1][x-2]==0)c++;
		if(x+2<n&&map[y+1][x+2]==0)c++;
	}return c;
}
int step(int y,int x){
	int min=10,label;
	if(y-2>=0){
		if(x+1<n){
			int tmp=count(y-2,x+1);
			if(map[y-2][x+1]==0&&min>tmp){
				min=tmp;
				label=1;
			}
		}
	}
	if(y-1>=0){
		if(x+2<n){
			int tmp=count(y-1,x+2);
			if(map[y-1][x+2]==0&&min>tmp){
				min=tmp;
				label=2;
			}
		}
	}
	if(y+1<n){
		if(x+2<n){
			int tmp=count(y+1,x+2);
			if(map[y+1][x+2]==0&&min>tmp){
				min=tmp;
				label=3;
			}
		}
	}
	if(y+2<n){
		if(x+1<n){
			int tmp=count(y+2,x+1);
			if(map[y+2][x+1]==0&&min>tmp){
				min=tmp;
				label=4;
			}
		}
	}
	if(y+2<n){
		if(x-1>=0){
			int tmp=count(y+2,x-1);
			if(map[y+2][x-1]==0&&min>tmp){
				min=tmp;
				label=5;
			}
		}
	}
	if(y+1<n){
		if(x-2>=0){
			int tmp=count(y+1,x-2);
			if(map[y+1][x-2]==0&&min>tmp){
				min=tmp;
				label=6;
			}
		}
	}
	if(y-1>=0){
		if(x-2>=0){
			int tmp=count(y-1,x-2);
			if(map[y-1][x-2]==0&&min>tmp){
				min=tmp;
				label=7;
			}
		}
	}
	if(y-2>=0){
		if(x-1>=0){
			int tmp=count(y-2,x-1);
			if(map[y-2][x-1]==0&&min>tmp){
				min=tmp;
				label=8;
			}
		}
	}
	if(min==10)return 9;
	return label;
}
int main(){
	Knight knight[10000];
	scanf("%d%d",&n,&m);
	int total=m;
	for(int i=0;i<m;i++){
		scanf("%d%d",&knight[i].y,&knight[i].x);
		knight[i].live=1;
		map[knight[i].y][knight[i].x]=(i+1)*10000;
	}int timer=0;

	while(total){
		timer++;
		for(int i=0;i<m;i++){
			if(knight[i].live==1){
				int label=step(knight[i].y,knight[i].x);
				//printf("%d\n",label);
				if(label==1){
					knight[i].y-=2;
					knight[i].x+=1;
					map[knight[i].y][knight[i].x]=10000*(i+1)+timer;
				}else if(label==2){
					knight[i].y-=1;
					knight[i].x+=2;
					map[knight[i].y][knight[i].x]=10000*(i+1)+timer;
				}else if(label==3){
					knight[i].y+=1;
					knight[i].x+=2;
					map[knight[i].y][knight[i].x]=10000*(i+1)+timer;
				}else if(label==4){
					knight[i].y+=2;
					knight[i].x+=1;
					map[knight[i].y][knight[i].x]=10000*(i+1)+timer;
				}else if(label==5){
					knight[i].y+=2;
					knight[i].x-=1;
					map[knight[i].y][knight[i].x]=10000*(i+1)+timer;
				}else if(label==6){
					knight[i].y+=1;
					knight[i].x-=2;
					map[knight[i].y][knight[i].x]=10000*(i+1)+timer;
				}else if(label==7){
					knight[i].y-=1;
					knight[i].x-=2;
					map[knight[i].y][knight[i].x]=10000*(i+1)+timer;
				}else if(label==8){
					knight[i].y-=2;
					knight[i].x-=1;
					map[knight[i].y][knight[i].x]=10000*(i+1)+timer;
				}else if(label==9){
					knight[i].live=0;
					total--;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d%c",map[i][j]," \n"[j==n-1]);
		}
	}
}
