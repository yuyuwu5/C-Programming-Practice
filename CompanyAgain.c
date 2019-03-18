#include <stdio.h>
#include <string.h>
#include <assert.h>
//#include "employee.h"
 
typedef struct employee {
  char first_name[32];
  char last_name[32];
  struct employee *boss;
} Employee;

int relation(Employee *employee1, Employee *employee2){
    Employee *a=employee1;
    Employee *b=employee2;
    while(a!=a->boss){
        a=a->boss;
        if(!strcmp(a->first_name,employee2->first_name) && !strcmp(a->last_name,employee2->last_name))
            return 1;
    }a=employee2;
    while(a!=a->boss){
        a=a->boss;
        if(!strcmp(a->first_name,employee1->first_name) && !strcmp(a->last_name,employee1->last_name))
            return 2;
    }
    a=employee1;
    while(a!=a->boss){
        a=a->boss;
    }while(b!=b->boss){
        b=b->boss;
    }if(!strcmp(a->first_name,b->first_name) && !strcmp(a->last_name,b->last_name)){
        return 3;
    }return 4;
}
typedef struct me {
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
} employee;
 
void readName(employee *e) {
    scanf("%s %s", e->first_name, e->last_name);
}
 
int nameToIndex(employee *e, employee A[], int n) {
    for (int i = 0; i < n; i++) {
        if (!strcmp(A[i].first_name, e->first_name) &&
            !strcmp(A[i].last_name, e->last_name))
            return i;
    }
    return -1;
}
int main() {
    int n, m;
    employee A[32];
    Employee B[32];
    const char out[4][32] = {"subordinate", "supervisor", "colleague", "unrelated"};
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i].id);
            readName(&A[i]);
            scanf("%d", &A[i].boss_id);
        }
 
        for (int i = 0; i < n; i++) {
            strcpy(B[i].first_name, A[i].first_name);
            strcpy(B[i].last_name, A[i].last_name);
            B[i].boss = NULL;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i].boss_id == A[j].id)
                    B[i].boss = &B[j];
            }
        }
        scanf("%d", &m);
        employee x, y;
        for (int i = 0; i < m; i++) {
            readName(&x);
            readName(&y);
            int ix = nameToIndex(&x, A, n), iy = nameToIndex(&y, A, n);
            assert(ix != -1);
            assert(iy != -1);
            printf("%d\n", relation(&B[ix], &B[iy]));
        }
    }
    return 0;
}