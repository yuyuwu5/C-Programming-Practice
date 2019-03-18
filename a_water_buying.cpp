#include<bits/stdc++.h>
using namespace std;
int main(){
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		long long int n,a,b;
		scanf("%lld%lld%lld",&n,&a,&b);
		if(b/a>=2){
			printf("%lld\n",n*a);
		}else{
			printf("%lld\n",(n/2)*b+(n%2)*a);
		}
	}
}
