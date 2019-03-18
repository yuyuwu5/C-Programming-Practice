#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#include"heap.h"
int isFull(struct Heap *heap){
    return heap->num==MAXHEAP;
}int isEmpty(struct Heap *heap){
    return heap->num==0;
}
void initialize(struct Heap *heap){
    memset(heap->ary,0,sizeof(heap->ary));
    heap->num=0;
}int removeMin(struct Heap *heap){
    int ans=heap->ary[1];
    heap->ary[1]=heap->ary[heap->num--];
    int now=1;
    while(now<heap->num){
        int sw;
        if(now*2>heap->num){
            break;
        }else if(now*2==heap->num){
            sw=now*2;
        }else{
            sw=heap->ary[now*2]<heap->ary[now*2+1]?now*2:now*2+1;
        }if(heap->ary[sw]>heap->ary[now]){
            break;
        }else{
		int tmp=heap->ary[sw];
		heap->ary[sw]=heap->ary[now];
		heap->ary[now]=tmp;
		now=sw;
        }
    }return ans;
}void add(struct Heap *heap, int i){
    int now=++heap->num;
    heap->ary[heap->num]=i;
    while(now!=1){
        if(heap->ary[now]<heap->ary[now/2]){
            swap(heap->ary[now],heap->ary[now/2]);
        }now/=2;
    }
}
