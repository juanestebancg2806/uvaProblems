#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;

int coins[5] = {1,5,10,25,50};
int mem[5][7500];

int solve(int i,int n){
	int ans;
	if(i < 5 && mem[i][n] != -1)
		ans = mem[i][n];
	else if(n == 0)
		ans = 1;
	else if(i == 5 && n != 0)
		ans = 0;
	else{
		ans = 0;
		if (coins[i] <= n)
			ans += solve(i,n-coins[i]);
		ans += solve(i+1,n);
	}
	if(i < 5)
		mem[i][n] = ans;
	return ans;
}

int main(){
	int N;
	ms(mem,-1);
	while(cin>>N){
		cout<<solve(0,N)<<endl;
	}
	return 0;
}