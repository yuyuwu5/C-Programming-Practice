#include <stdio.h>
#include <string.h>
typedef struct{
	int sys,data;
}Set;
int eval(int exp[]){
	Set s[1024];
	for(int i=1;i<=exp[0];i++){
		s[i-1].sys=1;
		s[i-1].data=exp[i];
	}
	for(int i=0;i<exp[0];i++){
		if(!s[i].sys)continue;
		if(i%2==1){
			if(s[i].data==1||s[i].data==2||s[i].data==3||s[i].data==4){
				if(s[i].data==3){
					int pre=0,k=1;
					while(pre==0){
						pre=s[i-k].sys;
						k++;
					}k--;
					s[i-k].data*=s[i+1].data;
					s[i].sys=0;
					s[i+1].sys=0;
				}else if(s[i].data==4){
					int pre=0,k=1;
					while(pre==0){
						pre=s[i-k].sys;
						k++;
					}k--;
					if(s[i+1].data==0)return -2147483647;
					s[i-k].data/=s[i+1].data;
					s[i].sys=0;
					s[i+1].sys=0;
				}
			
			}else return -2147483646;
		}
	}for(int i=0;i<exp[0];i++){
		if(s[i].sys==0)continue;
		if(i%2==1){
			if(s[i].data==1){
				int pre=0,k=1;
				while(pre==0){
					pre=s[i-k].sys;
					k++;
				}k--;
				s[i-k].data+=s[i+1].data;
				s[i].sys=0;
				s[i+1].sys=0;
			}else if(s[i].data==2){
				int pre=0,k=1;
				while(pre==0){
					pre=s[i-k].sys;
					k++;
				}k--;
				s[i-k].data-=s[i+1].data;
				s[i].sys=0;
				s[i+1].sys=0;
			}
		}
	}return s[0].data;
}
int main() {
    int exp[1024];
    memset(exp, -1, sizeof(exp));
    scanf("%d", &exp[0]);
    for (int i = 1; i <= exp[0]; i++)
        scanf("%d", &exp[i]);
    int ret = eval(exp);
    printf("%d\n", ret);
    return 0;
}
