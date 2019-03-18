#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
typedef struct{
	int value;
	char name[128];
}set;
typedef struct {
	int weight,a1,a2;
	set active[2],inactive[5];
}Medicine;
void init(Medicine *medicine){
	medicine->weight=medicine->a1=medicine->a2=0;
}
int addActive(Medicine *medicine, char *name, int weight){
	for(int i=0;i<medicine->a1;i++)if(strcmp(medicine->active[i].name,name)==0){
		medicine->active[i].value+=weight;
		medicine->weight+=weight;
		return medicine->active[i].value;
	}
	if(medicine->a1==2)return -1;
	strcpy(medicine->active[medicine->a1].name,name);
	medicine->active[medicine->a1++].value=weight;
	medicine->weight+=weight;
	return medicine->active[medicine->a1-1].value;
}
int addInactive(Medicine *medicine, char *name, int weight){
	for(int i=0;i<medicine->a2;i++)if(strcmp(medicine->inactive[i].name,name)==0){
		medicine->inactive[i].value+=weight;
		medicine->weight+=weight;
		return medicine->inactive[i].value;
	}
	if(medicine->a2==5)return -1;
	strcpy(medicine->inactive[medicine->a2].name,name);
	medicine->inactive[medicine->a2++].value=weight;
	medicine->weight+=weight;
	return medicine->inactive[medicine->a2-1].value;
}
int cmp(const void *p1,const void *p2){
	set *s1=(set*)p1,*s2=(set*)p2;
	if(s1->value<s2->value)return 1;
	if(s1->value>s2->value)return -1;
	return strcmp(s1->name,s2->name);
}
void print(Medicine *medicine){
	qsort(medicine->active,medicine->a1,sizeof(set),cmp);
	qsort(medicine->inactive,medicine->a2,sizeof(set),cmp);
	printf("----- Active Ingredient begin   -----\r\n");
	for(int i=0;i<medicine->a1;i++)printf("%d %s\r\n",medicine->active[i].value,medicine->active[i].name);
	printf("----- end                       -----\r\n");
	printf("----- Inactive Ingredient begin -----\r\n");
	for(int i=0;i<medicine->a2;i++)printf("%d %s\r\n",medicine->inactive[i].value,medicine->inactive[i].name);
	printf("----- end                       -----\r\n");
}
int totalWeight(Medicine *medicine){
	return medicine->weight;
}
char *maxIngredient(Medicine *medicine){
	if(medicine->a1==0&&medicine->a2==0)return NULL;
	qsort(medicine->active,medicine->a1,sizeof(set),cmp);
	qsort(medicine->inactive,medicine->a2,sizeof(set),cmp);
	if(medicine->a1==0){
		return medicine->inactive[0].name;
	}if(medicine->a2==0){
		return medicine->active[0].name;
	}if(medicine->active[0].value>medicine->inactive[0].value)return medicine->active[0].name;
	if(medicine->inactive[0].value>medicine->active[0].value)return medicine->inactive[0].name;
	if(strcmp(medicine->active[0].name,medicine->inactive[0].name)<0)return medicine->active[0].name;
	if(strcmp(medicine->active[0].name,medicine->inactive[0].name)>0)return medicine->inactive[0].name;
}
void test_all() {
    int n, m;
    scanf("%d %d", &n, &m);
 
    Medicine *medi = (Medicine *) malloc(sizeof(Medicine) * n);
    int cmd, mid, weight;
    char name[128];
    for (int i = 0; i < n; i++)
        init(&medi[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &cmd, &mid);
        if (cmd == 1) {         // addActive
            scanf("%s %d", name, &weight);
            int af = addActive(&medi[mid], name, weight);
            printf("af %d\r\n", af);
        } else if (cmd == 2) {    // addInactive
            scanf("%s %d", name, &weight);
            int bf = addInactive(&medi[mid], name, weight);
            printf("bf %d\r\n", bf);
        } else if (cmd == 3) {    // print
            print(&medi[mid]);
        } else if (cmd == 4) {    // totalWeight
            printf("weight = %d\r\n", totalWeight(&medi[mid]));
        } else if (cmd == 5) {    // maxIngredient
            char *ret = maxIngredient(&medi[mid]);
            printf("main ingredient = %s\r\n", ret == NULL ? "NOT FOUND" : ret);
        }
    }
}
int main() {
    test_all();
    return 0;
}
