#include<stdio.h>
#include<stdlib.h>
struct node {
       struct node *next;
};

struct node *getNode(struct node *head, unsigned int i){
	struct node *ptr=head;
	int count=0;
	while(ptr->next != NULL)
		count++;
	if(i>count)
		return NULL;
	ptr=head;
	while(i>0){
		ptr=ptr->next;
		--i;
	}
	return ptr;
}
