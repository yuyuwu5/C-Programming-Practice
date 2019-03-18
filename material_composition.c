#include<stdio.h>
int n,a[3],d[3],e[3],f[3],get;
void check(int a,int b,int c){
	if(get)return;
	if(a%d[0]==0&&b%d[1]==0&&c%d[2]==0&&a/d[0]==b/d[1]&&b/d[1]==c/d[2]){
		if(!get)printf("yes\n");
		get=1;
		return;
	}else if(a-d[0]>0&&b-d[1]>0&&c-d[2]>0)check(a-d[0],b-d[1],c-d[2]); 
	if(a%e[0]==0&&b%e[1]==0&&c%e[2]==0&&a/e[0]==b/e[1]&&b/e[1]==c/e[2]){
		if(!get)printf("yes\n");
		get=1;
		return;
	}else if(a-e[0]>0&&b-e[1]>0&&c-e[2]>0)check(a-e[0],b-e[1],c-e[2]); 
	if(a%f[0]==0&&b%f[1]==0&&c%f[2]==0&&a/f[0]==b/f[1]&&b/f[1]==c/f[2]){
		if(!get)printf("yes\n");
		get=1;
		return;	
	}else if(a-f[0]>0&&b-f[1]>0&&c-f[2]>0)check(a-f[0],b-f[1],c-f[2]); 
	if(a%(d[0]+e[0])==0&&b%(d[1]+e[1])==0&&c%(d[2]+e[2])==0&&a/(d[0]+e[0])==b/(d[1]+e[1])&&b/(d[1]+e[1])==c/(d[2]+e[2])){
		if(!get)printf("yes\n");
		get=1;
		return;
	}else if(a-d[0]-e[0]>0&&b-d[1]-e[1]>0&&c-d[2]-e[2]>0)check(a-d[0]-e[0],b-d[1]-e[1],c-d[2]-e[2]); 
	if(a%(d[0]+f[0])==0&&b%(d[1]+f[1])==0&&c%(d[2]+f[2])==0&&a/(d[0]+f[0])==b/(d[1]+f[1])&&b/(d[1]+f[1])==c/(d[2]+f[2])){
		if(!get)printf("yes\n");
		get=1;
		return;
	}else if(a-d[0]-f[0]>0&&b-d[1]-f[1]>0&&c-d[2]-f[2]>0)check(a-d[0]-f[0],b-d[1]-f[1],c-d[2]-f[2]); 
	if(a%(f[0]+e[0])==0&&b%(f[1]+e[1])==0&&c%(f[2]+e[2])==0&&a/(f[0]+e[0])==b/(f[1]+e[1])&&b/(f[1]+e[1])==c/(f[2]+e[2])){
		if(!get)printf("yes\n");
		get=1;
		return;	
	}else if(a-f[0]-e[0]>0&&b-f[1]-e[1]>0&&c-f[2]-e[2]>0)check(a-f[0]-e[0],b-f[1]-e[1],c-f[2]-e[2]); 
	if(a%(d[0]+e[0]+f[0])==0&&b%(d[1]+e[1]+f[1])==0&&c%(d[2]+e[2]+f[2])==0&&a/(d[0]+e[0]+f[0])==b/(d[1]+e[1]+f[1])&&b/(d[1]+e[1]+f[1])==c/(d[2]+e[2]+f[2])){
		if(!get)printf("yes\n");
		get=1;
		return;
	}else if(a-d[0]-e[0]-f[0]>0&&b-d[1]-e[1]-f[1]>0&&c-d[2]-e[2]-f[2]>0)check(a-d[0]-e[0]-f[0],b-d[1]-e[1]-f[1],c-d[2]-e[2]-f[2]); 
}
void rec(int now){
	if(now==0)return;
	get=0;
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	check(a[0],a[1],a[2]);
	if(!get)printf("no\n");
	rec(now-1);
}int main(){
	scanf("%d%d%d%d%d%d%d%d%d%d",&d[0],&d[1],&d[2],&e[0],&e[1],&e[2],&f[0],&f[1],&f[2],&n);
	rec(n);
}
