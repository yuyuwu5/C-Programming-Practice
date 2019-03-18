#include<stdio.h>
#include<stdlib.h>
int in[105],n=0;
typedef struct{
	int left,right,length;
}p;
typedef struct{
	int ind1,ind2,length;
}two;
p keep[1000000];
two t[1000000];
int test(int l,int r){
	int total=r-l+1;
	for(int i=0;i<total/2+1;i++){
		if(in[l+i]!=in[r-i])return 0;
	}return 1;
}int cmp(const void *p1,const void *p2){
	two *s1=(two*)p1,*s2=(two*)p2;
	if(s1->length<s2->length)return 1;
	if(s1->length>s2->length)return -1;
	if(keep[s1->ind2].right<keep[s2->ind2].right)return 1;
	if(keep[s1->ind2].right>keep[s2->ind2].right)return -1;
}int main(){
	int c=0,c_t=0;
	while(scanf("%d",&in[n++])!=EOF);
	n--;
	for(int l=0;l<n;l++){
		for(int r=n-1;r>=l;r--){
			if(test(l,r)){
				keep[c].left=l;
				keep[c].length=r-l+1;
				keep[c++].right=r;
			}
		}
	}for(int i=0;i<c;i++){
		for(int j=i+1;j<c;j++){
			if(keep[i].right+1==keep[j].left){
				t[c_t].ind1=i;
				t[c_t].ind2=j;
				t[c_t++].length=keep[i].length+keep[j].length;
			}
		}
	}qsort(t,c_t,sizeof(two),cmp);
	for(int i=0;i<keep[t[0].ind1].length;i++){
		printf("%d ",in[keep[t[0].ind1].left+i]);
	}for(int i=0;i<keep[t[0].ind2].length;i++){
		printf("%d%c",in[keep[t[0].ind2].left+i]," \n"[i==keep[t[0].ind2].length-1]);
	}
}
	
