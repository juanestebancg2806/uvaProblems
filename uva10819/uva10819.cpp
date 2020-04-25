#include <iostream>
#include <climits>
#include <cfloat>
#include <string.h>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define INF 10000
using namespace std;

int prices[105],favour[105],budget;
int mem[101][(100*4200)+1];
int M,N;

int solve(int i,int n){
	int ans;
	if(mem[i][n] != -1)
		ans = mem[i][n];
	else if((n > M &&  M < 1800) || n > M+200 || (i == N && (n > M && n <= 2000)))
		ans = -INF;
	else if(i == N)
		ans = 0;
	else
		ans = max(solve(i+1,n),solve(i+1,n+prices[i])+favour[i]);
	return mem[i][n] = ans;
}


int main(){
	int i,ans;
	while(cin>>M>>N){
		ms(mem,-1);
		for(i = 0; i < N;i++)
			cin>>prices[i]>>favour[i];
		ans = solve(0,0);
		cout<<ans<<endl;

	}
	return 0;
}