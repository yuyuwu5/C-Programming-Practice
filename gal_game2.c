#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include<time.h>
double dis(double x1,double x2,double y1,double y2,double z1,double z2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2);
} 
double frandom() {
    //srand(1234567);
    return rand() * 1.f / RAND_MAX;
} 
int main(){
    int n,a,b,count=0;
    while(scanf("%d%d",&n,&a)!=EOF){
        count++;
        int x[9],y[9],z[9],ans[9]={0};
        for(int i=0;i<a;++i){
            scanf("%d%d%d",&x[i],&y[i],&z[i]);
        }for(int k=0;k<100000;k++){ 
            double tmp_x,tmp_y,tmp_z,min=100000000;
            do{
		    tmp_x=frandom()*n;
		    tmp_y=frandom()*n;
		    tmp_z=frandom()*n;
	    }while(dis(tmp_x,0,tmp_y,0,tmp_z,0)>n*n*n);
	    int minptr;
	    if(frandom()>=0.5)tmp_x=-tmp_x;
	    if(frandom()>=0.5)tmp_y=-tmp_y;
	    if(frandom()>=0.5)tmp_z=-tmp_z; 
            for(int i=0;i<a;++i){
                double tmp=dis(x[i],tmp_x,y[i],tmp_y,z[i],tmp_z);
                if(tmp<min){
                    min=tmp;
                    minptr=i;
                }
            }ans[minptr]++;
        }
        printf("Case #%d:\n",count);
        for(int i=0;i<a;++i){
            printf("%d\n",(int)round((double)ans[i]*100/(double)100000));
            //printf("%d\n",(int)round((double)ans[i]*100/(double)300000));
        }
    }
}
