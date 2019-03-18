#include<stdio.h>
int abs(int a){
	if(a<0)return -a;
	return a;
}int dis(int x1,int y1,int z1,int x2,int y2,int z2){
	return abs(x1-x2)+abs(y1-y2)+abs(z1-z2);
}
int main(){
	int x,y,z,mx,my,mz,bx,by,bz,n,explode=0,gone=0,instruct;
	scanf("%d%d%d%d%d%d%d%d%d%d",&x,&y,&z,&mx,&my,&mz,&bx,&by,&bz,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&instruct);
		if(explode)continue;
		if(instruct==1)x++;
		else if(instruct==2)x--;
		else if(instruct==3)y++;
		else if(instruct==4)y--;
		else if(instruct==5)z++;
		else if(instruct==6)z--;
		int mine,hole=100000;
		if(!gone)hole=dis(x,y,z,bx,by,bz);
		mine=dis(x,y,z,mx,my,mz);
		if(mine<10){
			explode=1;
			x=mx,y=my,z=mz;
		}else if(hole<10){
			gone=1;
			x=bx,y=by,z=bz;
		}if(!explode&&(i+1)%5==0)printf("%d %d %d\n",x,y,z);
	}
}
