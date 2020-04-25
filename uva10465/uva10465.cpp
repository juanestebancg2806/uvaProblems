#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define INF 99999999
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;

int n,m;
int mem[10001];

int solve(int t){
	int ans;
	if(t < 0)
		ans = -INF;
	else{
		if(mem[t] != -1)
			ans = mem[t];
		else if(t == 0)
			ans = 0;
		else
			ans = max(1+solve(t-n),1+solve(t-m));
		mem[t] = ans;

	}
	return ans;
}

int main(){

	int t,ans,i;
	bool ok;
	while(cin>>n>>m>>t){
		ok = false;
		ms(mem,-1);
		i = 0;
		ans = solve(t);
		if(ans < 0){
			while (i < t+1 && !ok){
				ok = mem[i] != -1;
				i += 1;
			}
			cout<<solve(t-(i-1))<<" "<<i-1<<endl;
		}
		else
			cout<<ans<<endl;

	}
	
	return 0;
}