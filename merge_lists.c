#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>

#define LEN 1000
 
struct node {
    int value;
    struct node * next;
};

struct node *head=NULL,*move;
struct node * merge(struct node *h1, struct node *h2){
	if(h1==NULL&&h2==NULL)return head;
	if(h1!=NULL&&h2!=NULL){
	if(h1->value<h2->value){
		if(head==NULL){
			head=h1;
			move=h1;
		}else{
			move->next=h1;
			move=h1;
		}merge(h1->next,h2);
	}else if(h1->value>h2->value){
		if(head==NULL){
			head=h2;
			move=h2;
		}else{
			move->next=h2;
			move=h2;
		}merge(h1,h2->next);
	}}
	if(h1==NULL){
		move->next=h2;
		move=h2;
		merge(h1,h2->next);
	}else if(h2==NULL){
		move->next=h1;move=h1;merge(h1->next,h2);
	}
}
 

struct node * build(int v[], int n) {
    struct node * head, * ptr;
    int i;

    if (!n)
        return 0;

    head = (struct node *) malloc(sizeof(struct node));
    ptr = head;
    head -> value = v[0];
    for (i = 1; i < n; i++) {
        ptr -> next = (struct node *) malloc(sizeof(struct node));
        ptr = ptr -> next;
        ptr -> value = v[i];
    }
    ptr -> next = 0;
    return head;
}

void print(struct node * ptr) {
    printf("%d", ptr -> value);
    if (ptr -> next) {
        putchar(' ');
        print(ptr -> next);
    }
}

int main() {
    int n1, n2;
    int v1[LEN], v2[LEN];
    int i;
    struct node * list1, * list2;

    scanf("%d", &n1);
    for (i = 0; i < n1; i++)
        scanf("%d", &v1[i]);
    scanf("%d", &n2);
    for (i = 0; i < n2; i++)
        scanf("%d", &v2[i]);
    list1 = build(v1, n1);
    list2 = build(v2, n2);

    print(merge(list1, list2));
    putchar('\n');
    return 0;
}
