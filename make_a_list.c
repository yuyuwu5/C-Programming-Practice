#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int v;
    struct Node *next;
} Node;
static long long seed = 1;
int sp_rand() {
       return (seed = (seed * 9301 + 49297) % 233280);
}
void sp_srand(long long t) {
    seed = t;
} 
Node* mk_list(int n) {
    Node *head;
    Node *move=NULL;
    for (int i = 0; i < n; i++) {
        Node *u;
	u=(Node*)malloc(sizeof(Node));
        u->v = sp_rand(), u->next = NULL;
        if(!move)head=u;
	else move->next=u;
	move=u;
    }return head;
}
void rm_list(Node *head) {
    while(head){
	    Node *pre=head;
	    head=head->next;
	    free(pre);
    }
} 
int main() {
    int n;
    long long s;
 
    scanf("%lld", &s);
    sp_srand(s);
    while (scanf("%d", &n) == 1) {
        Node *list = mk_list(n);
        Node *u = list;
        for (int i = 0; i < n; ) {
            long long sum = 0;
            int cnt = 1;
            while (u && cnt < 100000) {
                sum += u->v * cnt;
                u = u->next, cnt++;
                i++;
            }
            printf("%lld\n", sum);
        }
        rm_list(list);
    }
    return 0;
}
