#include <stdio.h>
#include<stdlib.h>
#define MAXN 262144
typedef struct activity {
    int start;
    int end;
} Activity;
 
int cmp(const void *p1,const void *p2){
	Activity *s1=(Activity*)p1,*s2=(Activity*)p2;
	if(s1->end<s2->end)return -1;
	if(s1->end>s2->end)return 1;
	if(s1->start<s2->start)return 1;
	return -1;
}
int Select(Activity activities[], int n){
	qsort(activities,n,sizeof(Activity),cmp);
	int now=0,count=0;
	for(int i=0;i<n;i++){
		if(activities[i].start>=now){
			count++;
			now=activities[i].end;
#ifdef PRINT
			printf("%d %d\n",activities[i].start,activities[i].end);
#endif
		}
	}return count;
}

Activity A[MAXN];
int main() {
    int n, cases = 0;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++)
            scanf("%d %d", &A[i].start, &A[i].end);
        int ret = Select(A, n);
        printf("%d\n", ret);
    }
    return 0;
}
