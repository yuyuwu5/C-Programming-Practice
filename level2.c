#include <stdio.h>
#include<stdlib.h>
int **t2[100],*t1[5000];
int ***constructTable(int A[], int B[]){
	int total_in_a=0,total_in_b=0;
	while(A[total_in_a]!=0){
		total_in_b+=A[total_in_a++];
	}int now_b=0;
	for(int i=0;i<total_in_b;i++){
		t1[i]=&B[now_b];
		int k=0;
		while(B[k+now_b]!=0)k++;
		now_b+=k+1;
	}
	int count=0;
	for(int i=0;i<total_in_a;i++){
		t2[i]=&t1[count];
		for(int j=0;j<A[i];j++)count++;
	}return t2;
}
int main(){
    int N, M;
    int A[100] = {}, B[500] = {};
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i < M; i++)
        scanf("%d", &B[i]);
 
    int ***ptr;
    ptr = constructTable(A, B);
    for(int i = 0; *(ptr+i) != NULL; i++)
        for(int j = 0; j < A[i]; j++)
            for(int k = 0; *(*(*(ptr+i)+j)+k) != 0; k++)
                printf("%d ", *(*(*(ptr+i)+j)+k));
    return 0;
}
