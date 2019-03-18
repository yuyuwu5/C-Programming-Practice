#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1048576
long long int belt[MAXSIZE];
void transmission(long long int belt[],int N,int T){
	T%=64*N;
	int change=T/64,shift=T%64;
	long long t=1,file[65]={0};
	for(int i=1;i<65;i++){
		file[i]=t;
		t=t<<1;
	}long long add[2]={0};
	for(int i=N-1;i>=0;i--){
		for(int j=0;j<shift;j++){
			add[i%2]=add[i%2]<<1;
			if(belt[i]&file[64-j])add[i%2]++;
		}for(int j=0;j<shift;j++)belt[i]=belt[i]<<1;
		belt[i]+=add[(i+1)%2];
		add[(i+1)%2]=0;
	}if(add[0]==0)belt[N-1]+=add[1];
	else belt[N-1]+=add[0];
	long long *out=(long long*)malloc(sizeof(long long)*change);
	for(int i=0;i<change;i++)out[i]=belt[i];
	for(int i=0;i<N-change;i++)belt[i]=belt[i+change];
	for(int i=N-change;i<N;i++)belt[i]=out[i-N+change];
}
int main(){
    int N,T;
    scanf("%d%d",&N,&T);
    for(int i=0;i<N;i++)
        scanf("%lld",&belt[i]);
    transmission(belt,N,T);
    for(int i=0;i<N;i++)
        printf("%lld%s",belt[i],i==N-1?"":"\n");
    return 0;
}
