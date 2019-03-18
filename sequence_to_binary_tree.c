#include<stdio.h>
#include<stdlib.h>
#define MAXN 16384

typedef struct node{
    int value;
    struct node *left, *right;
} Node;
typedef struct {
	int index,value;
}sort;
int cmp(const void *p1,const void *p2){
	sort *s1=(sort*)p1,*s2=(sort*)p2;
	if(s1->value<s2->value)return 1;
	return -1;
}
Node *build(int seq[],int left,int right){
	if(right<left)return NULL;
	int total=right-left+1;
	sort s[16384];
	Node *root=(Node*)malloc(sizeof(Node));
	if(total<MAXLENGTH){
		Node *pre=NULL;
		for(int i=right;i>=left;i--){
			Node *t=(Node*)malloc(sizeof(Node));
			t->value=seq[i];
			t->right=NULL;
			t->left=NULL;
			if(!pre)root=t;
			else{
				pre->left=t;
			}pre=t;
		}return root;
	}for(int i=left;i<=right;i++){
		s[i-left].value=seq[i];
		s[i-left].index=i;
	}qsort(s,total,sizeof(sort),cmp);
	root->value=s[MAXLENGTH-1].value;
	root->left=build(seq,left,s[MAXLENGTH-1].index-1);
	root->right=build(seq,s[MAXLENGTH-1].index+1,right);
	return root;
}Node *ConstructTree(int sequence[], int N){
	return build(sequence,0,N-1);
}
int sequence[MAXN];
 
void PrintTree( Node *root ){
    if (root == NULL)
        return;
    printf("%d\n", root->value);
    PrintTree(root->left);
    PrintTree(root->right);
    return;
}
int main(){
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &sequence[i]);
    Node *tree = ConstructTree( sequence, N );
    PrintTree( tree );
    return 0;
}
