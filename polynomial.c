#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
typedef struct{
	int co[4096],count;
}Polynomial;
void init(Polynomial *poly, int coefficient[], int n){
	poly->count=n;
	for(int i=0;i<n;i++){
		poly->co[i]=coefficient[i];
	}
}
Polynomial add(Polynomial *poly1, Polynomial *poly2){
	int max=poly1->count;
	if(max<poly2->count)max=poly2->count;
	Polynomial t;
	t.count=max;
	for(int i=0;i<max;i++){
		t.co[i]=poly1->co[i]+poly2->co[i];
	}return t;
}
Polynomial multiply(Polynomial *poly1, Polynomial *poly2){
	Polynomial t;
	t.count=poly1->count+poly2->count-1;
	for(int i=0;i<4096;i++)t.co[i]=0;
	for(int i=0;i<poly1->count;i++){
		for(int j=0;j<poly2->count;j++){
			t.co[i+j]+=poly1->co[i]*poly2->co[j];
		}
	}return t;
}
void print(Polynomial *poly){
	for(int i=poly->count-1;i>1;i--){
		if(poly->co[i]==0)continue;
		else if(poly->co[i]>0)printf("+");
		printf("%dx^%d",poly->co[i],i);
	}if(poly->co[1]>0)printf("+");
	if(poly->co[1]!=0)printf("%dx",poly->co[1]);
	if(poly->co[0]>0)printf("+");
	if(poly->co[0]!=0)printf("%d",poly->co[0]);
	puts("");
}
void test_specall() {
    int n, m;
    int cmds, cmd, pid, pid2;
    int v[4096];
    scanf("%d", &n);
    Polynomial *p = (Polynomial*) malloc(sizeof(Polynomial)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
            scanf("%d", &v[j]);
        init(&p[i], v, m);
    }
    scanf("%d", &cmds);
    for (int i = 0; i < cmds; i++) {
        scanf("%d %d", &cmd, &pid);
        if (cmd == 1) {
            print(&p[pid]);
        } else if (cmd == 2) {
            scanf("%d", &pid2);
            Polynomial ret = add(&p[pid], &p[pid2]);
            print(&ret);
        } else if (cmd == 3) {
            scanf("%d", &pid2);
            Polynomial ret = multiply(&p[pid], &p[pid2]);
            print(&ret);
        } else {
            assert(0);
        }
    }
}
int main() {
    test_specall();
    return 0;
}
