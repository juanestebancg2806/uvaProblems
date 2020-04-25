#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <limits.h>
#include <cmath>
#define INF INT_MAX
#define lli  long long int
#define ms(a,b) memset(a,b,sizeof(a))

using namespace std;

lli ans[30002];
int coins[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};



void solve(){
	int i,j;
	for(i = 0; i < 11; i++){
		for(j = 0; j < 30001; j++){
			if(coins[i] <= j)
				ans[j] += ans[j-coins[i]];
		}
	}
}



int main(){
	double inp;
	lli n;ms(ans,0);
	ans[0] = 1;
	solve();
	cin>>inp;
	n = (int)(round(inp*100));
	while(n){
		printf("%6.2f%17lli\n",inp,ans[n]);
		cin>>inp;
		n = (int)(round(inp*100));
	}
	return 0;
}