#include<stdio.h>
#include<stdlib.h>
typedef struct tree_node{
	int data,level;
	struct tree_node *parent,*left,*right;
}node;
node *root=NULL;
void build(int data,int level){
	node *tmp=(node*)malloc(sizeof(node));
	node *now=root;
	tmp->parent=NULL;
	tmp->left=NULL;
	tmp->right=NULL;
	tmp->data=data;
	tmp->level=level;
	if(!root)root=tmp;
	while(now){
		if(tmp->data<now->data){
			if(now->left)now=now->left;
			else{
				tmp->parent=now;
				now->left=tmp;
				break;
			}
		}else if(tmp->data>now->data){
			if(now->right)now=now->right;
			else{
				tmp->parent=now;
				now->right=tmp;
				break;
			}
		}
	}
}node *find(int data,node *tmp){
	if(tmp->data==data)return tmp;
	if(tmp->data<data)find(data,tmp->right);
	else find(data,tmp->left);
}void go(node *start,node *stop){
	int distance=0;
	node *strt,*stp;
	if(start->level>stop->level){
		strt=start;
		stp=stop;
	}else{
		strt=stop;
		stp=start;
	}while(strt->level>stp->level){
		strt=strt->parent;
		distance++;
	}while(strt->level==stp->level&&strt->data!=stp->data){
		strt=strt->parent;
		stp=stp->parent;
		distance+=2;
	}printf("%d\n",distance);
}	
typedef struct pair{
	int data,level;
}pair;
int compare(const void *p1,const void *p2){
	pair *s1=(pair*)p1;
	pair *s2=(pair*)p2;
	if(s1->level<s2->level)return -1;
	if(s1->level>s2->level)return 1;
	if(s1->data<s2->data)return -1;
	return 1;
}int main(){
	int n,m,a,b;
	pair p[1000];
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",&p[i].data,&p[i].level);
	qsort(p,n,sizeof(pair),compare);
	for(int i=0;i<n;i++)build(p[i].data,p[i].level);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		node *t,*tt;
		t=find(a,root);
		tt=find(b,root);
		go(t,tt);
	}
}
