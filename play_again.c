#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
	struct Node *left, *right,*pre;
	char c;
	int data,child;
}Node;
Node *root=NULL;
void print(Node *head){
	if(head->left)print(head->left);
	printf("%c %d ",head->c,head->data);
	printf("child %d\n",head->child);
	if(head->right)print(head->right);
}
Node *initial(char c,int data){
	Node *t=(Node*)malloc(sizeof(Node));
	t->left=NULL;
	t->right=NULL;
	t->pre=NULL;
	t->data=data;
	t->child=data;
	t->c=c;
	return t;
}
int insert_left(char c,int num,Node *head){		
	if(!head){
		Node *t=initial(c,num);
		root=t;
		return 0;
	}
	if(head->left)head->child+=insert_left(c,num,head->left);
	else {
		if(head->c!=c){	
			Node *t=initial(c,num);
			t->pre=head;
			head->left=t;
			head->child+=t->data;
		}else{
			head->data+=num;
			head->child+=num;
		}
	}
	return num;
}
int insert_right(char c,int num,Node *head){		
	if(!head){
		Node *t=initial(c,num);
		root=t;
		return 0;
	}
	if(head->right)head->child+=insert_right(c,num,head->right);
	else { 
		if(head->c!=c){
			Node *t=initial(c,num);
			t->pre=head;
			head->right=t;
			head->child+=t->data;
		}else{
			head->data+=num;
			head->child+=num;
		}
	}
	return num;
}
int kkk;
Node *search(Node *head){
	if(head->left&&kkk<=head->left->child){
		return search(head->left);
	}
	if(head->left)kkk-=head->left->child;
	if(kkk<=head->data)return head;
	kkk-=head->data;
	return search(head->right);
}
void insert(int k,char c,int data,Node *head){
	kkk=k;
	Node *t=search(head);
	if(t->c==c){
		t->data+=data;
		while(t){
			t->child+=data;
			t=t->pre;
		}
		return;
	}
	printf("find %c %d %d ",t->c,t->data,t->child);	
	printf("kkk= %d\n",kkk);
}
int main(){
	char command[20];
	while(scanf("%s",command)!=EOF){
		Node *head=root;
		if(strcmp(command,"print")==0){
			if(head)print(head);
			printf("$\n");
		}else if(strcmp(command,"insert")==0){
			char com[20],c[3];
			int num;
			scanf("%s%s%d",com,c,&num);
			if(strcmp(com,"left")==0){
				insert_left(c[0],num,head);
			}else if(strcmp(com,"right")==0){
				insert_right(c[0],num,head);
			}else{
				int kth=atoi(com);
				insert(kth,c[0],num,head);
			}
		}
	}
}
