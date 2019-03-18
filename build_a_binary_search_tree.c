#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bstNode* bstNode_getLson(bstNode *self) {
    return self->lson;
}
bstNode* bstNode_getRson(bstNode *self) {
    return self->rson;
}
void bstNode_setLson(bstNode *self, bstNode *u) {
    self->lson = u;
}
void bstNode_setRson(bstNode *self, bstNode *u) {
    self->rson = u;
}
void bstNode_print(bstNode *self) {
    printf("%d ", *(int *)(self->extra));
}

int bstNode_init(bstNode *obj) {
    obj->getLson = bstNode_getLson;
    obj->getRson = bstNode_getRson;
    obj->setLson = bstNode_setLson;
    obj->setRson = bstNode_setRson;
    obj->print = bstNode_print;
    obj->extra = (void *) malloc(sizeof(int));
    return 1;
}
void bstNode_destroy(bstNode *obj) {
    free(obj->extra);
}

Object bstNodeProto = {
    .init = bstNode_init,
    .destroy = bstNode_destroy
};

bstNode* buildBST(int A[], int n) {
	bstNode *root=NULL;
	for(int i=0;i<n;i++){
		bstNode *t=(bstNode*)malloc(sizeof(bstNode));
		t->l
}
void dfsPrint(bstNode *u) {
    if (u == NULL)    return;
    u->print(u);
    dfsPrint(u->getLson(u));
    dfsPrint(u->getRson(u));
    FREE(bstNode, u);
}
void demo(bNode *u)  {
    if (u == NULL)    return;
    u->print(u);
    demo(u->getLson(u));
    demo(u->getRson(u));    
    FREE(bNode, u);
}
int main() {
/*
    bNode *t, *u;
    t = NEW(bNode);
    u = NEW(bNode);
    t->setLson(t, u);
    u->setRson(u, NEW(bNode));
    demo(t);
    */
    int N;
    while (scanf("%d", &N) == 1 && N) {
        int *A = (int *) malloc(sizeof(int)*N);
        for(int i = 0; i < N; i++)
            scanf("%d", &A[i]);
        bstNode *root = buildBST(A, N);
        dfsPrint(root);
        puts("");
        free(A);
    }
    return 0;
}
