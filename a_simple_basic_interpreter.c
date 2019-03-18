#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int value[105],var=0,line=1,words_in_line[1005]={0};
char variable[105][10],command[1005][15][20];
int search(char a[]){
	for(int i=0;i<var;i++)if(strcmp(variable[i],a)==0)return i;
}void read(){
	int now=1;
	while(1){
		if(strcmp(command[now][0],"IF")==0){
			int a=search(command[now][1]),b=search(command[now][3]);
			if(strcmp(command[now][2],">=")==0){
				if(value[a]>=value[b])now=atoi(command[now][5]);
				else now++;
			}else if(strcmp(command[now][2],"<=")==0){
				if(value[a]<=value[b])now=atoi(command[now][5]);
				else now++;
			}else if(strcmp(command[now][2],"==")==0){
				if(value[a]==value[b])now=atoi(command[now][5]);
				else now++;
			}else if(strcmp(command[now][2],"!=")==0){
				if(value[a]!=value[b])now=atoi(command[now][5]);
				else now++;
			}else if(command[now][2][0]=='>'){
				if(value[a]>value[b])now=atoi(command[now][5]);
				else now++;
			}else if(command[now][2][0]=='<'){
				if(value[a]<value[b])now=atoi(command[now][5]);
				else now++;
			}
		}else if(strcmp(command[now][0],"PRINT")==0){
			int a=search(command[now][1]);
			printf("%d\n",value[a]);
			now++;
		}else if(strcmp(command[now][0],"GOTO")==0){
			now=atoi(command[now][1]);
		}else if(strcmp(command[now][0],"STOP")==0){
			break;
		}else{
			int a=search(command[now][0]),b=search(command[now][2]),c=search(command[now][4]);
			if(command[now][3][0]=='+'){
				value[a]=value[b]+value[c];
			}
			else if(command[now][3][0]=='-'){
				value[a]=value[b]-value[c];
			}
			else if(command[now][3][0]=='*'){
				value[a]=value[b]*value[c];
			}
			else if(command[now][3][0]=='/'){
				value[a]=value[b]/value[c];
			}
			else if(command[now][3][0]=='%'){
				value[a]=value[b]%value[c];
			}now++;
		}
	}
}
int main(){
	int start=1;
	char in[10];
	while(start){
		scanf("%s",in);
		if(strcmp(in,"END")!=0){
			strcpy(variable[var],in);
			scanf("%s%d",in,&value[var++]);
		}else start=0;
	}
	while(scanf("%s",command[line][0])!=EOF){
		if(strcmp(command[line][0],"IF")==0){
			words_in_line[line]=6;
			for(int i=1;i<words_in_line[line];i++)scanf("%s",command[line][i]);
		}else if(strcmp(command[line][0],"PRINT")==0){
			words_in_line[line]=2;
			for(int i=1;i<words_in_line[line];i++)scanf("%s",command[line][i]);
		}else if(strcmp(command[line][0],"GOTO")==0){
			words_in_line[line]=2;
			for(int i=1;i<words_in_line[line];i++)scanf("%s",command[line][i]);
		}else if(strcmp(command[line][0],"STOP")==0){
			words_in_line[line]=1;
		}else{
			words_in_line[line]=5;
			for(int i=1;i<words_in_line[line];i++)scanf("%s",command[line][i]);
		}line++;
	}read();
}
