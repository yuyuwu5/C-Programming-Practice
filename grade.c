#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
	int n,w,r;
	while(scanf("%d%d%d",&n,&w,&r)!=EOF){
		int correct[50][5]={0};
		char c[5];
		for(int i=0;i<n;i++){
			scanf("%s",c);
			int len=strlen(c);
			for(int j=0;j<len;j++){
				correct[i][c[j]-'A']=1;
			}
		}int p,score;
		scanf("%d",&p);
		for(int i=0;i<p;i++){
			score=0;
			int stu[50][5]={0};
			for(int j=0;j<n;j++){
				scanf("%s",c);
				int len=strlen(c);
				if(strcmp(c,"N/A")==0)continue;
				for(int k=0;k<len;k++){
					if(islower(c[k]))stu[j][c[k]-'a']=1;
					else stu[j][c[k]-'A']=1;
				}int err=0;
				for(int k=0;k<5;k++){
					if(correct[j][k]!=stu[j][k]){
						score-=r;
						err=1;
						break;
					}
				}if(!err)score+=w;
			}if(score<0)score=0;
			printf("%d\n",score);
		}
	}
}

