#include<stdio.h>
#include<limits.h>
int main(){
	int n,list[20],stop[20]={0};
	char name[20][20];
	scanf("%d",&n);
	FILE *fp[20];
	for(int i=0;i<n;i++){
		scanf("%s",name[i]);
		fp[i]=fopen(name[i],"rb");
		fread(&list[i],sizeof(int),1,fp[i]);
	}
	int c=0;
	while(1){
		int small=INT_MAX,id;
		for(int i=0;i<n;i++){
			if(stop[i]==0){
				if(small>list[i]){
					small=list[i];
					id=i;
				}
			}
		}
		printf("%d\n",small);
		fread(&list[id],sizeof(int),1,fp[id]);
		if(feof(fp[id])){
			stop[id]=1;
			c++;
			if(c==n)break;
		}
	}
}
