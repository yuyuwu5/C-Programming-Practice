#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int input[105],sum=0;
	for(int i=0;i<n;i++){ 
		scanf("%d",&input[i]);
		sum+=input[i];
	}
	if(sum<m){
		printf("-1\n");
		return 0;
	}
	sort(input,input+n,greater<int>());
	int day=0,wrote=0;
	vector <int> v;
	v.assign(input,input+n);
	int process=0,tmp,minus;
	sum=0;
	while(wrote<m){
		minus=1;
		day++;
		wrote+=v[process];
		tmp=process+1;
		while(v[tmp]-minus>0){
			sum+=v[tmp]-minus;
			tmp++;
			minus++;
		}
		printf("%d\n",sum);
		if(wrote+sum>=m){
			printf("%d\n",day);
			return 0;
		}
		process++;
	}
}
