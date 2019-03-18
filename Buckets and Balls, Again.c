#include<stdio.h>
//#include"placement.h"

void place(int bucket[1024],int N,int ball[16384],int M,int method,int result[16384])
{
    int i, j, min = 10000000, s, max = -1, k;
    switch(method){
case 0:
    for(i = 0; i < M; i++){
     for(j = 0; j < N; j++){
       if(ball[i] <= bucket[j]){
            bucket[j] -= ball[i];
            result[i] = j;
            break;
       }
       else
        result[i] = -1;
    }
    }
    break;

case 1:
    for(i = 0; i < M; i++){
     for(j = 0; j < N; j++){
            if(bucket[j] - ball[i] >= 0)
            if(min > (bucket[j] - ball[i])){
             min = bucket[j] - ball[i];
             s = j;
            }
     }
     if(min == 10000000)
        result[i] = -1;
     else{
        bucket[s] -= ball[i];
        result[i] = s;
     }
     min = 10000000;
    }

    break;

case 2:
    for(i = 0; i < M; i++){
     for(j = 0; j < N; j++){
            if(bucket[j] - ball[i] >= 0)
            if(max <= (bucket[j] - ball[i])){
             max = bucket[j] - ball[i];
             k = j;
            }
     }
     if(max == -1)
        result[i] = -1;
     else{
        bucket[k] -= ball[i];
        result[i] = k;
     }
     max = -1;
    }
    break;
}
}
int main(){
    int N,M,method;
    scanf("%d%d%d",&N,&M,&method);
    int buckets[N];
    for(int i=0;i<N;i++)
        scanf("%d",&buckets[i]);
    int balls[M];
    for(int i=0;i<M;i++)
        scanf("%d",&balls[i]);
    int result[M];
    place(buckets,N,balls,M,method,result);
    for(int i=0;i<M;i++)
        printf("%d%s",result[i],i==M-1?"":" ");
    return 0;
}
