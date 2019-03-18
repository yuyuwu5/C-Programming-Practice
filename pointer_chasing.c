#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void chasing(int **A[], int a, int *B[], int b, int C[], int c){
	for(int i=0;i<a;i++)A[i]=NULL;
	for(int i=0;i<b;i++)B[i]=NULL;
	char in[100]={0};
	int not=0;
	while(fgets(in,100,stdin)!=0){
		if(not)continue;
		char deli[]=" ",*s=in,p[64][64]={0};
		int count=0;
		if(strcmp(in,"endtest\n")==0){
			not=1;
			continue;
		}s=strtok(s,deli);
		while(s){
			strcpy(p[count++],s);
			s=strtok(NULL,deli);
		}if(count!=4||strlen(p[0])!=1||strlen(p[2])!=1){
			printf("0\n");
			continue;
		}int stop=0;
		for(int i=0;i<strlen(p[1])-1;i++){
			if(!isdigit(p[1][i])){
				printf("0\n");
				stop=1;
				break;
			}
		}if(stop)continue;
		for(int i=0;i<strlen(p[3])-1;i++){
			if(!isdigit(p[3][i])){
				printf("0\n");
				stop=1;
				break;
			}
		}if(stop)continue;
		if(p[0][0]!='A'&&p[0][0]!='B'){
			printf("0\n");
			continue;
		}if(p[0][0]=='A'&&p[2][0]!='B' ||p[0][0]=='B'&&p[2][0]!='C' ){
			printf("0\n");
			continue;
		}int num1=atoi(p[1]),num2=atoi(p[3]);
		if(p[0][0]=='A'){
			if(num1>=a||num2>=b){
				printf("0\n");
				continue;
			}
			A[num1]=&B[num2];
			printf("1\n");
			continue;
		}if(p[0][0]=='B'){
			if(num1>=b||num2>=c){
				printf("0\n");
				continue;
			}B[num1]=&C[num2];
			printf("1\n");
		}
	}
}
int main() {
        int a = 5, b = 4, c = 3;
        int **A[3] = {}, *B[3] = {}, C[3] = {2, 1, 4};
        chasing(A, a, B, b, C, c);

        int **ansA[3] = {} ,*ansB[3] = {};
        for (int i = 0; i < a; i++)
                ansA[i] = NULL;
        for (int i = 0; i < b; i++)
                ansB[i] = NULL;
        ansA[0] = &B[0], ansA[1] = &B[2], ansB[0] = &C[2], ansB[1] = &C[1];
        /*Check A*/
        for (int i = 0; i < a; i++)
                if (A[i] != ansA[i] )
                        printf("A[%d] wrong answer!\n", i);

        /*Check B*/
        for (int i = 0; i < b; i++)
                if (B[i] != ansB[i] )
                        printf("B[%d] wrong answer!\n", i);
        return 0;

}
