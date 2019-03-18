#include<stdio.h>
#include<string.h>

int main(void)
{
	char variable[1002][10];
	int a=1,i=0;
	while(a != 0){
		scanf("%s",variable[i]);
		a=strcmp(variable[i],'END');
		i++;
	}
}
