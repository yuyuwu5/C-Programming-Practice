#include<stdio.h>
#include <stdlib.h>
#include <string.h> 
 
typedef struct Doll {
    char top, bottom;
    struct Doll *interior;
} Doll;
 
Doll *newDoll(char top, char bottom){
	Doll *new=(Doll*)malloc(sizeof(Doll));
	new->top=top;
	new->bottom=bottom;
	new->interior=NULL;
	return new;
}void package(Doll *outer, Doll *inter){
	outer->interior=inter;
}char ala[1000000]={0},*kll=ala;
int now=0;
void make(Doll *doll){
	ala[now++]=doll->top;
	if(doll->interior)make(doll->interior);
	ala[now++]=doll->bottom;
}const char* doll_c_str(Doll *doll){
	now=0;
	for(int i=0;i<1000;i++)ala[i]=0;
	make(doll);
	return kll;
}int main() {
	Doll *dolls[16];
	dolls[0] = newDoll('<', '~');
	dolls[1] = newDoll('(', ')');
	dolls[2] = newDoll('@', '>');
	dolls[3] = newDoll('#', '#');
	package(dolls[1], dolls[2]);
	package(dolls[0], dolls[1]);
	printf("%s\n", doll_c_str(dolls[0]));
	printf("%s\n", doll_c_str(dolls[3]));
	package(dolls[3], dolls[1]);
	printf("%s\n", doll_c_str(dolls[3]));
	printf("%s\n", doll_c_str(dolls[0]));
	return 0;
}
