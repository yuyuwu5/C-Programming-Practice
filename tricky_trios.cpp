#include<bits/stdc++.h>
using namespace std;
#define first F
#define second S
void add(vector<vector<pair<int, int> > >dp,int a,int b,int c,int d){
	int tmp_u,tmp_d;
	tmp_u=b*dp[c][d].F+a*dp[c][d].S;
	tmp_d=b*dp[c][d].S;
	int k=__gcd(tmp_u,tmp_d);
	dp[c][d].F=tmp_u/k;
	dp[c][d].S=tmp_d/k;
}
void fill(vector<vector<pair<int, int> > >dp,int ways[101]){
	for(int i=2;i<=100;i++){
		int total=i*3,up=1,down=1,f,s;
		//get in one round;
		up=6*i;
		down=total*(total-1)*(total-2);
		for(int j=1;j<=ways[i-1];j++){
			f=dp[i-1][j].F*up;
			s=dp[i-1][j].S*down;
			add(dp,f,s,i,j+1);
		}
		//get in second round

		//get in third round

	}
}
int main(){
	vector<vector<pair<int,int> > >dp;
	for(int i=0;i<=100;i++){ 
		vector<pair<int,int> >line(12000,make_pair(0,1));
		dp.push_back(line);
	}
	dp[1][1].F=1;
	dp[1][1].S=1;
	int ways[101]={0};
	ways[1]=1;
	fill(dp,ways);
	int t,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&n);
	}
}
