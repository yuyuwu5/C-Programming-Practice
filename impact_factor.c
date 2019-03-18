#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXP 1024
typedef struct {
    char journalName[64];
    int numCitedPaper;
    int citedPaperIndex[1024];
} paper;
typedef struct{
	char name[64];
	int id[1024],now,first,second;
}journal;
int Index[1000000]={0};
journal jour[1024];
int cmp(const void *p1,const void *p2){
	journal *s1=(journal*)p1,*s2=(journal*)p2;
	return strcmp(s1->name,s2->name);
}void compute(paper P[], int N){
	int count=0;
	for(int i=0;i<N;i++){
		int get=0;
		for(int j=0;j<count;j++){
			if(strcmp(P[i].journalName,jour[j].name)==0){
				get=1;
				jour[j].id[jour[j].now++]=i;
			}
		}if(!get){
			strcpy(jour[count].name,P[i].journalName);
			jour[count].id[0]=i;
			jour[count].now=1;
			jour[count].first=0;
			jour[count++].second=0;
		}for(int j=0;j<P[i].numCitedPaper;j++)Index[P[i].citedPaperIndex[j]]++;
	}qsort(jour,count,sizeof(journal),cmp);
	for(int i=0;i<count;i++){
		for(int j=0;j<jour[i].now;j++){
			jour[i].first+=Index[jour[i].id[j]];	
			if(Index[jour[i].id[j]])jour[i].second++;
		}printf("%s %d/%d\n",jour[i].name,jour[i].first,jour[i].second);
	}
}
int main() {
    int N;
    paper P[MAXP] = {};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s%d", P[i].journalName, &P[i].numCitedPaper);
        for (int j = 0; j < P[i].numCitedPaper; j++)
            scanf("%d", &P[i].citedPaperIndex[j]);
    }compute(P, N);
}
