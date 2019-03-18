#include <stdio.h> 
#include<stdlib.h>
#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512
typedef struct p{
	int pos;
	int times;
	int data;
}ppp;
int compare(const void *p1,const void *p2){
	ppp *q1=(ppp*)p1,*q2=(ppp*)p2;
	if(q1->times<q2->times)return -1;
	if(q1->times>q2->times)return 1;
	if(q1->data<q2->data)return -1;
	return 1;
}
ppp ps[512];
void count(int **p[]){
	int ***tmp=p;
	int count=0;
	while(tmp[count])tmp[count++];
	int *t=**tmp;
	int index=0;
	for(int i=0;i<count;i++){
		int yes=0;
		for(int j=0;j<index;j++){
			if(ps[j].pos==(int)&(**tmp[i])){
				yes=1;
				ps[j].times++;
				break;
			}
		}if(!yes){
			ps[index].pos=(int)&(**tmp[i]);
			ps[index].data=**tmp[i];
			ps[index++].times=1;
		}
	}qsort(ps,index,sizeof(ppp),compare);
	for(int i=0;i<index;i++)printf("%d %d\n",ps[i].data,ps[i].times);
} 
 
int main(){
  int **ptrArray[MAX_SIZE_PTRARRAY] = {};
  int  *intPtr[MAX_NUM_PTR];
  int   intVar[MAX_NUM_INTVAR];
 
  intVar[0] = 7;
  intVar[1] = 6;
  intVar[2] = 2;
  intVar[3] = 9;
  ptrArray[0] = &intPtr[0];
  ptrArray[1] = &intPtr[1];
  ptrArray[2] = &intPtr[2];
  ptrArray[3] = &intPtr[3];
  ptrArray[4] = NULL;
  intPtr[0] = &intVar[0];
  intPtr[1] = &intVar[1];
  intPtr[2] = &intVar[2];
  intPtr[3] = &intVar[3];
 
  count(ptrArray);
 
  return 0;
}