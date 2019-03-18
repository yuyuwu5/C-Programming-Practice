#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	char name[32];
	int grade[256];
}person;
typedef struct{
	int dim_n,count;
	person people[256];
}ExamTable;
void init(ExamTable *self,int n){
	self->dim_n=n;
	self->count=0;
}void addrow(ExamTable *self,char *name,int score[]){
	strcpy(self->people[self->count].name,name);
	for(int i=0;i<self->dim_n;i++)self->people[self->count].grade[i]=score[i];
	self->count++;
}int max,*o;
int cmp(const void *p1,const void *p2){
	person *s1=(person*)p1,*s2=(person*)p2;
	for(int i=0;i<max;i++){
		if(s1->grade[o[i]]<s2->grade[o[i]])return 1;
		if(s1->grade[o[i]]>s2->grade[o[i]])return -1;
	}return strcmp(s1->name,s2->name);
}void print(ExamTable *self,int order[]){
	o=order;
	max=self->dim_n;
	qsort(self->people,self->count,sizeof(person),cmp);
	printf("----- table begin -----\n");
	for(int i=0;i<self->count;i++){
		printf("%s, ",self->people[i].name);
		for(int j=0;j<self->dim_n-1;j++){
			printf("%d, ",self->people[i].grade[j]);
		}printf("%d\n",self->people[i].grade[self->dim_n-1]);
	}printf("----- end         -----\n");	       	
}
int main() {
    const int MAXETB = 8;
    int etb_n, dim_n;
    int cmds, cmd, tid, score[128], sort_order[128];
    char sid[32];
    ExamTable *etb = (ExamTable*) malloc(sizeof(ExamTable)*MAXETB);
    scanf("%d", &etb_n);
    for (int i = 0; i < etb_n; i++) {
        scanf("%d", &dim_n);
        init(&etb[i], dim_n);
    }scanf("%d", &cmds);
    for (int i = 0; i < cmds; i++) {
        scanf("%d %d", &cmd, &tid);
        if (cmd == 1) {
            scanf("%s", sid);
            for (int j = 0; j < etb[tid].dim_n; j++)
                scanf("%d", &score[j]);
            addrow(&etb[tid], sid, score);
        } else {
            for (int j = 0; j < etb[tid].dim_n; j++)
                scanf("%d", &sort_order[j]);
            print(&etb[tid], sort_order);
        }
    }
}
