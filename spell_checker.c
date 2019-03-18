#include<stdio.h>
#include<string.h>
char dictionary[100000][100];
int n;
int abs(int k){
	if(k<0)return -k;
	return k;
}void search(char in[]){
	int l=strlen(in),found=0;
	char candi[1000][100]={0};
	for(int i=0;i<n;i++){
		int l1=strlen(dictionary[i]);
		if(abs(l1-l)>1)continue;
		if(l1<l){
			int skip=0;
			for(int j=0;j<l1;j++){
				while(j+skip<l&&dictionary[i][j]!=in[j+skip])skip++;
			}if(skip<=1){
				strcpy(candi[found++],dictionary[i]);
			}
		}else if(l1>l){
			int skip=0;
			for(int j=0;j<l;j++){
				while(j+skip<l1&&dictionary[i][j+skip]!=in[j])skip++;
			}if(skip<=1){
				strcpy(candi[found++],dictionary[i]);
			}
		}else if(l1==l){
			int diff=0;
			for(int j=0;j<l;j++){
				if(dictionary[i][j]!=in[j])diff++;
			}if(diff==0){
				printf(">%s\n",in);
				return;
			}if(diff==1){
				strcpy(candi[found++],dictionary[i]);
			}
		}
	}if(!found)printf("!%s\n",in);
	else {
		printf("?%s",candi[0]);
		for(int i=1;i<found;i++)printf(" %s",candi[i]);
		printf("\n");
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%s",dictionary[i]);
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++){
		char in[100];
		scanf("%s",in);
		search(in);
	}
}

