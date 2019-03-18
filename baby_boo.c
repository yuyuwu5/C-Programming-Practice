#include<stdio.h>
#include<string.h>
int main(){
	int n;
	char boo[100000];
	scanf("%s%d",boo,&n);
	int length=strlen(boo);
	for(int i = 0; i < n; i++){
		char tmp1[3],tmp2[3];
		scanf("%s%s",tmp1,tmp2);
		for(int j = 0; j < length; j++){
			if(boo[j]==tmp2[0]){
				boo[j]=tmp1[0];
			}
		}
	}printf("%s",boo);
}	
