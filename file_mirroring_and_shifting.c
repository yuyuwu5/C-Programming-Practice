#include<stdio.h>
int main(){
	char in[17],out[17];
	int n;
	scanf("%s%s%d",in,out,&n);
	FILE *f1=fopen(in,"rb");
	FILE *f2=fopen(out,"wb");
	fseek(f1,0,SEEK_END);
	long length=ftell(f1);
	for(int i=0;i<length;i++){
		unsigned char a,b=0;
		fseek(f1,-(((n=i)%length)+1),SEEK_END);
		fread(&a,1,1,f1);
		for(int j=0;j<8;j++)if(a&(1<<j))b|=1<<(7-j);
		fwrite(&b,1,1,f2);
	}fclose(f1);
	fclose(f2);
}
