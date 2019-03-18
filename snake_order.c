#include<stdio.h>
int snake(int *ptr, int *row, int *column){
	int total;
	for(total=0;ptr;total++){
		if(total>0&&ptr[total]==0)break;
	}
	int c=1;
	for(int i=1;i<total;i++){
		if(ptr[i]==ptr[i-1]+1)c++;
		else break;
	}*column=c;
	*row=total/c;
	for(int i=0;i<*row;i++){
		for(int j=1;j<*column;j++){
			if(ptr[*column*i+j]!=ptr[*column*i+j-1]+1){
				*row=i;
				*column=j;
				return 0;
			}
		}i++;
		if(i>=*row)break;
		for(int j=1;j<*column;j++){
			if(ptr[*column*i+j]!=ptr[*column*i+j-1]-1){
				*row=i;
				*column=j;
				return 0;
			}
		}
	}return 1;
	/*
	for(int i=0;i<total;i+=2*c){
		for(int j=i+1;j<i+c;j++){
			if(ptr[j]!=ptr[j-1]+1){
				*row=j/c;
				*column=j%c;
				return 0;
			}
		}if(i+2*c-2<total)
		for(int j=i+2*c-2;j>=i+c;j--){
			if(ptr[j]!=ptr[j+1]-1){
				*row=j/c;
				*column=j%c;
				return 0;
			}
		}
	}return 1;*/
}
int main(void)
{
    int trav[1024] = {0}, row = 0, column = 0, res = 0;
    scanf("%d %d", &trav[0], &trav[1]);
    for(int i = 1; trav[i]; i++)
      scanf("%d", &trav[i + 1]);
    res = snake(trav, &row, &column);
    if(res) printf("%d %d\n", row, column);
    else printf("err %d %d\n", row, column);
    return 0;
}

