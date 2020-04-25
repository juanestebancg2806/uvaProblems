#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cstring>
using namespace std;

int coins[101];
int dp[51000];




int solve(int N,int M){
	memset(dp,0,sizeof(dp));
	int n = 1,m = M;
	while(n != N+1){
		if(m == -1){
			n += 1;
			m = M;
		}
		else{
			if(coins[n-1]<=m)
				dp[m] = max(dp[m],coins[n-1]+dp[m-coins[n-1]]);
			m -= 1;
		}
	}
	return dp[M];
}

int main(){
	int tc,i,N,sumCoins,M,ans;
	cin>>tc;
	while(tc--){
		cin>>N;
		sumCoins = 0;
		memset(coins,0,sizeof(coins));
		for(i = 0; i < N;i++){
			cin>>coins[i];
			sumCoins += coins[i];
		}
		M = sumCoins/2;
		ans = sumCoins-solve(N,M);
		ans = abs(ans-(sumCoins-ans));
		cout<<ans<<endl;

	}
	return 0;
}