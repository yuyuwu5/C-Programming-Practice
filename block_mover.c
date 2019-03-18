#include<stdio.h>
void printBlock(unsigned long long int *block){
	unsigned long long a=1;
	for(int i=1;i<=64;i++){
		if(*block&a)printf("1");
		else printf("0");
		if(i%8==0)puts("");
		a=a<<1;
	}
}
void initialize(unsigned long long int *block, int row, int column, int size){
	unsigned long long a=0;
	*block=0;
	for(int i=0;i<size;i++){
		a=a<<1;
		a++;
	}a=a<<column;
	a=a<<8*row;
	for(int i=row;i<row+size;i++){
		*block|=a;
		a=a<<8;
	}
}
int moveLeft(unsigned long long int *block){
	unsigned long long int out=72340172838076673;
	if(*block&out)return 0;
	*block=*block>>1;
	return 1;
}
int moveRight(unsigned long long int *block){
	unsigned long long out=9259542123273814144;
	if(*block&out)return 0;
	*block=*block<<1;
	return 1;
}
int moveUp(unsigned long long int *block){
	unsigned long long out=255;
	if(*block&out)return 0;
	*block=*block>>8;
	return 1;
}
int moveDown(unsigned long long int *block){
	unsigned long long int out=18374686479671623680;
	if(*block&out)return 0;
	*block=*block<<8;
	return 1;
}
int main() {
    unsigned long long int num;
    char operation;
    int ret;

    scanf("%llu", &num);
    while (1) {
        ret = 1;

        scanf("%c", &operation);

        if (operation == 'p') {
            printBlock(&num);
            break;
        } else if (operation == 'u')
            ret = moveUp(&num);
        else if (operation == 'd')
            ret = moveDown(&num);
        else if (operation == 'l')
            ret = moveLeft(&num);
        else if (operation == 'r')
            ret = moveRight(&num);
        else if (operation == 'i') {
            int row, column, size;
            scanf("%d %d %d", &row, &column, &size);
            initialize(&num, row, column, size);
        }

        if (ret == 0)
            printf("Invalid move!\n");
    }

    return 0;
}
