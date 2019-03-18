#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,l;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&l);
		long long e,n,small=0;
		for(int j=0;j<l;j++){ 
			scanf("%lld%lld",&n,&e);
			if(small-n*e<=0)small=0;
			else small-=n*e;
			small+=n;
		}
		printf("Case #%d: %lld\n",i+1,small<e?e+1:small);
	}
}
