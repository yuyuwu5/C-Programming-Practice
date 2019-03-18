#include<stdio.h>
void print(int n,int a[],int temp[])
{
	for(int i = 0; i < n; i++){
		//printf("%d ",temp[i]);
		printf("%d",a[temp[i]-1]);
		if(i<n-1)printf(" ");
	}
	printf("\n");
}
void sort(int n,int a[],int temp[],int k)
{
	temp[k]=0;
	while(temp[k]++<n){
		int collision=0;
		for(int i = 0; i < k && !collision;i++)
			if(temp[i]==temp[k]){collision=1;}
		if(!collision){
			if(k+1<n){sort(n,a,temp,k+1);}
			else{print(n,a,temp);}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[10];
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	for(int i = n-2; i >=0;i--){
		for(int j = 0; j <=i;j++)
			if(a[j]>a[j+1]){
				int temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
	}
	int temp[10]={0};
	sort(n,a,temp,0);
}