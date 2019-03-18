#include<stdio.h>
int main(){
	char file[205];
	scanf("%s",file);
	FILE *fp=fopen(file,"rb");
	int frequency[70000]={0},max=0,max_data,n;
	short num;
	fread(&n,4,1,fp);
	while(fread(&num,2,1,fp)!=0){
		frequency[num+32768]++;
		if(frequency[num+32768]>max){
			max=frequency[num+32768];
			max_data=num;
		}else if(frequency[num+32768]==max&&max_data<num)max_data=num;
	}printf("%d\n%d\n",max_data,max);
	fclose(fp);
}
