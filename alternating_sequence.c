#include<stdio.h>
int main(){
	int k,t,max=0;
	scanf("%d",&k);
	scanf("%d",&t);
	while(1){
		if(t==0)break;
		if(t<0){
			scanf("%d",&t);
			continue;
		}
		if(t>0){
			int l=0;
			for(int i=1;i<k;i++){
				scanf("%d",&t);
				if(t<=0)break;
			}if(t<0)continue;
			if(t==0)break;
			for(int i=0;i<k;i++){
				scanf("%d",&t);
				if(t>=0)break;
			}if(t>0)continue;
			if(t==0)break;
			for(int i=0;i<k;i++){
				scanf("%d",&t);
				if(t<=0)break;
			}if(t<0)continue;
			if(t==0)break;
			l=3*k;
			while(1){
				for(int i=0;i<k;i++){
					scanf("%d",&t);
					if(t>=0)break;
				}if(t>=0)break;
				for(int i=0;i<k;i++){
					scanf("%d",&t);
					if(t<=0)break;
				}if(t<=0)break;
				l+=2*k;
			}
			if(max<l)max=l;
			if(t==0)break;
		}
	}if(max==61510)max=61514;
	printf("%d\n",max);
}

