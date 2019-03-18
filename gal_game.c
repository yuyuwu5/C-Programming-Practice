#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double dis(double x1,double x2,double y1,double y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
} 
double frandom() {
    return rand() * 1.f / RAND_MAX;
} 
int main(){
    int n,a,b,count=0;
    while(scanf("%d%d%d",&n,&a,&b)!=EOF){
        count++;
        int x[9],y[9],ans[9]={0};
        for(int i=0;i<n;++i){
            scanf("%d%d",&x[i],&y[i]);
        }for(int k=0;k<150000;k++){
            double tmp_x=frandom()*a ,tmp_y=frandom()*b,min=10000000;
            int minptr;
            for(int i=0;i<n;++i){
                double tmp=dis(x[i],tmp_x,y[i],tmp_y);
                if(tmp<min){
                    min=tmp;
                    minptr=i;
                }
            }ans[minptr]++;
        }
        printf("Case #%d:\n",count);
        for(int i=0;i<n;++i){
            printf("%d\n",(int)round((double)ans[i]*100/(double)150000));
        }
    }
}
