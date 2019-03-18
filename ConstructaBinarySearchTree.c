#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "construct.h"
#define DHEIGHT

typedef struct Node{
    char name[16];
    int height;
    int weight;
    struct Node *left, *right;
} Node;

Node *insert_tree(Node *root,char name[16], int height, int weight)
{
    Node *student;
    #ifdef DHEIGHT
    if(root==NULL){
        student=(Node*)malloc(sizeof(Node));
        strcpy(student->name,name);
        student->height=height;
        student->weight=weight;
        student->left=NULL;
        student->right=NULL;
        return student;
    }
    if(height < root->height)
        root->left=insert_tree(root->left,name,height,weight);
    if(height > root->height)
        root->right=insert_tree(root->right,name,height,weight);
    #endif
    #ifdef DWEIGHT
    if(root==NULL){
        student=(Node*)malloc(sizeof(Node));
        strcpy(student->name,name);
        student->height=height;
        student->weight=weight;
        student->left=NULL;
        student->right=NULL;
        return student;
    }
    if(weight < root->weight)
        root->left=insert_tree(root->left,name,height,weight);
    if(weight > root->weight)
        root->right=insert_tree(root->right,name,height,weight);
    #endif
    return root;
}
Node *ConstructBSTree(int N, char name[][16], int height[], int weight[])
{
    Node *root_n = NULL;
    for(int i = 0; i < N; i++)
        root_n=insert_tree(root_n,name[i],height[i],weight[i]);
    return root_n;
}
#define MAXN 1024
char name[MAXN][16];
int height[MAXN];
int weight[MAXN];
 
void PrintBSTree( Node *root ){
    if (root == NULL)
        return;
    printf("%s\n", root->name);
    PrintBSTree(root->left);
    PrintBSTree(root->right);
    return;
}
 
int main(){
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%s %d %d", name[i], &height[i], &weight[i]);
 
    Node *tree = ConstructBSTree( N, name, height, weight );
 
    PrintBSTree( tree );
    return 0;
}