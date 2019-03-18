#include <stdio.h>
void merge(int A[], int B[], int* a[], int* b[]){
	int size_a=0,size_b=0;
	while(a[size_a++]);
	while(b[size_b++]);
	//size_a--;
	//size_b--;
	int now_a=0,now_b=0,turn;
	while(now_a<size_a&&now_b<size_b){
		if(A[now_a]<B[now_b]){
			if(A[now_a+1]<B[now_b]){
				a[now_a]=&A[now_a+1];
				now_a++;
			}else if(B[now_b]<A[now_a+1]){
				a[now_a]=&B[now_b];
				now_a++;
			}
		}else{
			if(B[now_b+1]<A[now_a]){
				b[now_b]=&B[now_b+1];
				now_b++;
			}else if(A[now_a]<B[now_b+1]){
				b[now_b]=&A[now_a];
				now_b++;
			}
		}
	}if(now_a<size_a){
		b[size_b-1]=&A[now_a];
	}else if(now_b<size_b){
		a[size_a-1]=&B[now_b];
	}
	//printf("%d %d\n",now_a,now_b);
}
int main()
{
    int A[10], B[10];
    int *a[10], *b[10], *ans_a[10], *ans_b[10];
    int i, N, M;
 
    scanf("%d%d", &N, &M);
    for(i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for(i = 0; i < M; i++)
        scanf("%d", &B[i]);
    for(i = 0; i < N-1; i++)
        a[i] = &A[i+1];
    a[N-1] = NULL;
    for(i = 0; i < M-1; i++)
        b[i] = &B[i+1];
    b[M-1] = NULL;
 
    merge(A, B, a, b);
 
    ans_a[0] = &B[0]; ans_a[1] = &A[2]; ans_a[2] = &B[1]; ans_a[3] = &B[2];
    ans_b[0] = &A[1]; ans_b[1] = &A[3]; ans_b[2] = NULL;
 
    for(i = 0; i < N; i++){
        if(a[i] != ans_a[i])
            printf("a[%d] is Wrong!\n", i);
    }
    for(i = 0; i < M; i++){
        if(b[i] != ans_b[i])
            printf("b[%d] is Wrong!\n", i);
    }
    printf("Finish!\n");
    return 0;
}
