#include<stdio.h>
long long area(int x1,int y1,int x2,int y2,int x3,int y3){
	int X1=x2-x1,X2=x3-x1,Y1=y2-y1,Y2=y3-y1;
	long long k=(X1*Y2-X2*Y1);
	if(k<0)k=-k;
	return k;
}int main(){
	int x[3],y[3];
	for(int i=0;i<3;i++)scanf("%d%d",&x[i],&y[i]);
	long long full=area(x[0],y[0],x[1],y[1],x[2],y[2]);
	int max_x=x[0],max_y=y[0],min_x=x[0],min_y=y[0];
	for(int i=0;i<3;i++){
		if(max_x<x[i])max_x=x[i];
		if(max_y<y[i])max_y=y[i];
		if(min_x>x[i])min_x=x[i];
		if(min_y>y[i])min_y=y[i];
	}int count=0;
	for(int i=min_y;i<=max_y;i++){
		for(int j=min_x;j<=max_x;j++){
			if(area(j,i,x[0],y[0],x[1],y[1])+area(j,i,x[0],y[0],x[2],y[2])+area(j,i,x[1],y[1],x[2],y[2])==full){
				if(area(j+1,i,x[0],y[0],x[1],y[1])+area(j+1,i,x[0],y[0],x[2],y[2])+area(j+1,i,x[1],y[1],x[2],y[2])==full){
					if(area(j,i+1,x[0],y[0],x[1],y[1])+area(j,i+1,x[0],y[0],x[2],y[2])+area(j,i+1,x[1],y[1],x[2],y[2])==full){
						if(area(j+1,i+1,x[0],y[0],x[1],y[1])+area(j+1,i+1,x[0],y[0],x[2],y[2])+area(j+1,i+1,x[1],y[1],x[2],y[2])==full){
				count++;
						}
					}
				}
			}
		}
	}printf("%d\n",count);
}
