#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char total[15000000]={0};
int main(){
    int n,one=0,two=0,pos=0,nF[1024]={0};
    char **level1[1025],*level2[16385],in[16385];
    scanf("%d\n",&n);
    level2[0]=total;
    for(int i=0;i<n;i++){
        level1[one++]=&level2[two];
        char ttt;
	while(scanf("%s%c",&total[pos],&ttt)!=EOF){
		level2[two++]=&total[pos];
		nF[i]++;
		pos+=strlen(&total[pos])+1;
		if(ttt=='\n')break;
	}
    }int m;
    scanf("%d\n",&m);
    for(int i=0;i<m;i++){
        int y1,x1,y2,x2;
        scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
        char *tmp1=level1[y1][x1],*tmp2=level1[y2][x2];
        level1[y1][x1]=tmp2;
        level1[y2][x2]=tmp1;
    }for(int i=0;i<one;i++){
        int kp;
        if(i<one-1){
            kp=level1[i+1]-level1[i];
            printf("%s",*(level1[i]));
            for(int j=1;j<kp;j++)printf(" %s",*(level1[i]+j));
        }else{
            int j=1;
            printf("%s",*(level1[i]));
            while(*(level1[i]+j)){
                printf(" %s",*(level1[i]+j++));
            }
        }printf("\n");
    }
}
