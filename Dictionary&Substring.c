#include<stdio.h>
#include<string.h>
int search(int n,char request[51],char dictionary[201][51])
{
	char *ptr;
	int count =0;
	for(int i = 0; i < n; i++){
		ptr = strstr(dictionary[i],request);
		if(ptr != NULL)count++;
	}
	return count;
}
int main()
{
	int n;
	scanf("%d",&n);
	char dictionary[201][51];
	for(int i = 0; i < n; i++)
		scanf("%s",dictionary[i]);
	int r;
	scanf("%d",&r);
	char request[51][51];
	for(int i=0; i < r; i++){
		scanf("%s",request[i]);
		printf("%d\n",search(n,request[i],dictionary));
	}
}