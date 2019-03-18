#include <stdio.h>
int add(int numbers[],int now,int sum,int n,int K,int S,int count){
	if(count==S&&sum==K)return 1;
	if(sum>K||now>=n||count>S)return 0;
	for(int i=now;i<n;i++){
		int j=add(numbers,i+1,sum+numbers[i],n,K,S,count+1);
		if(j==1)return j;
	}return 0;
}
int subset(int numbers[], int n, int K, int S){
	return add(numbers,0,0,n,K,S,0);
}	
int main() {
    int n, K, S;
    while (scanf("%d %d %d", &n, &K, &S) == 3) {
        int A[128];
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        printf("%d\n", subset(A, n, K, S));
    }
    return 0;
}
