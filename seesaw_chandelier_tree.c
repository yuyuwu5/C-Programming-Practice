#include <stdio.h>
#include<stdlib.h>
#define MAXN 16384
typedef struct Node{
    int value;
    struct Node *left, *right;
} Node;
Node *r=NULL;
Node *rec(int T[],int left,int center,int right){
	if(center>right||right-left<2){
		Node *h=NULL,*pre=NULL;
		for(int i=right;i>=left;i--){
			Node *new=(Node*)malloc(sizeof(Node));
			new->value=T[i];
			new->right=NULL;
			new->left=NULL;
			if(pre)pre->left=new;
			if(i==right)h=new;
			pre=new;
		}return h;
	}long long ll=0,rr=0;
	for(int i=left;i<center;i++)ll+=T[i]*(center-i);
	for(int i=center+1;i<=right;i++)rr+=T[i]*(i-center);
	if(rr==ll){
		Node *new=(Node*)malloc(sizeof(Node));
		new->value=T[center];
		if(!r)r=new;
		new->left=NULL;
		new->right=NULL;
		new->left=rec(T,left,left,center-1);
		new->right=rec(T,center+1,center+1,right);
		return new;
	}rec(T,left,center+1,right);
}
Node *ConstructTree(int T[], int N){
	rec(T,0,0,N-1);
	return r;
}

int T[MAXN];
 
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
        scanf("%d", &T[i]);
 
    Node *tree = ConstructTree( T, N );
 
    PrintTree( tree );
    return 0;
}
