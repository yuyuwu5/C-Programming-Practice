#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512
typedef struct{
	int data,times;
	int *where;
}P;
int cmp(const void *p1,const void *p2){
	P *s1=(P*)p1,*s2=(P*)p2;
	if(s1->times<s2->times)return -1;
	if(s1->times>s2->times)return 1;
	if(s1->data<s2->data)return -1;
	if(s1->data<s2->data)return 1;
}	
void count(int **p[]){
	int i=0,count=0;
	P point[512*512];
	while(p[i]){
		int get=0;
		for(int j=0;j<count;j++){
			if(point[j].where==&(**p[i])){
				point[j].times++;
				get=1;
				break;
			}
		}if(!get){
			point[count].data=**p[i];
			point[count].where=&(**p[i]);
			point[count++].times=1;
		}i++;
	}qsort(point,count,sizeof(P),cmp);
	for(i=0;i<count;i++)printf("%d %d\n",point[i].data,point[i].times);
}	
int main(){
  int **ptrArray[MAX_SIZE_PTRARRAY] = {};
  int  *intPtr[MAX_NUM_PTR];
  int   intVar[MAX_NUM_INTVAR];
 
  intVar[0] = 7;
  intVar[1] = 7;
  intVar[2] = 6;
  ptrArray[0] = &intPtr[0];
  ptrArray[1] = &intPtr[1];
  ptrArray[2] = &intPtr[2];
  ptrArray[3] = &intPtr[2];
  ptrArray[4] = &intPtr[3];
  ptrArray[5] = &intPtr[4];
  ptrArray[6] = NULL;
  intPtr[0] = &intVar[0];
  intPtr[1] = &intVar[1];
  intPtr[2] = &intVar[2];
  intPtr[3] = &intVar[2];
  intPtr[4] = &intVar[1];
 
  count(ptrArray);
 
  return 0;
}
