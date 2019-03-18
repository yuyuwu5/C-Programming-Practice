#include<stdio.h>
int out[24][8]={0},now=0,text[8]={0};
void transfer(unsigned long long num){
    while(num){
        int yes=0;
        for(int i=7;i>=0;i--){
            if(num&1){
                out[now][i]=1;
            }else out[now][i]=0;
            num=num>>1;
        }now++;
    }
}void small_trans(int k){
    for(int i=7;i>=0;i--){
        if(k&1)text[i]=1;
        else text[i]=0;
        k=k>>1;
    }
}void print(int *p){
    printf("%d\n",128*p[0]+64*p[1]+32*p[2]+16*p[3]+8*p[4]+4*p[5]+2*p[6]+p[7]);
}int main(){
    int n,m,p,left=0;
    scanf("%d%d%d",&n,&m,&p);
    if(n%8!=0)left=8*((n/8)+1)-n;
    unsigned long long correct[4];
    for(int i=0;i<m;i++){
        scanf("%llu",&correct[i]);
        transfer(correct[i]);
    }for(int i=0;i<p;i++){
        int num;
        scanf("%d",&num);
        small_trans(num);
        int diff,kkk;
        if(n%8==0)kkk=n/8;
        else kkk=(n/8)+1;
        for(int j=0;j<8*kkk;j++){
            int stop=0;
            for(int tmp=0;tmp<left;tmp++){
                if(8*(n/8)+tmp==j)stop=1;
            }if(stop)continue;
            diff=0;
            for(int k=0;k<8;k++){
                if(out[j][k]!=text[k])diff++;
            }if(diff==1||diff==0){
                print(out[j]);
                break;
            }
        }
    }
}
