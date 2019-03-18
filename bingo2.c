#include <stdio.h>
int bingo(const unsigned long long int *board, int *rowColumn){
	unsigned long long k=255,bing[20]={0};
	for(int i=0;i<8;i++){
		bing[i]=k;
		k=k<<8;
	}bing[8]=72340172838076673;
	bing[9]=2314885530818453536/16;
	bing[10]=2314885530818453536/8;
	bing[11]=2314885530818453536/4;
	bing[12]=2314885530818453536/2;
	bing[13]=2314885530818453536;
	bing[14]=4629771061636907072;
	bing[15]=9259542123273814144;
	bing[16]=9241421688590303745;
	bing[17]=72624976668147840;
	for(int i=7;i>=0;i--){
		if((bing[i]&*board)==bing[i]){
			*rowColumn=7-i;
			return 1;
		}
	}for(int i=15;i>=8;i--){
		if((bing[i]&*board)==bing[i]){
			*rowColumn=8-(i+1-8);
			return 2;
		}
	}if((bing[16]&*board)==bing[16]){
		*rowColumn=0;
		return 3;
	}if((bing[17]&*board)==bing[17]){
		*rowColumn=1;
		return 3;
	}return 0;
}
int main(void)
{
    unsigned long long int board;
    int res = 0, rowColumn = 0;
    scanf("%llu", &board);
    res = bingo(&board, &rowColumn);
    if(res == 0) printf("no\n");
    else printf("%d %d\n", res, rowColumn);
    return 0;
}
