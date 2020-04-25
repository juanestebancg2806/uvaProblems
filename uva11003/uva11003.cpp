#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define INF 999999999
using namespace std;

int mem[1001][6000];
int W[1001],L[1001];
int N;
int solve(int i,int n){
	int ans;
	if(n >= 0 && mem[i][n] != -1){
		ans = mem[i][n];
	}
	else if((i == N && n >= 0) || n == 0)
		ans = 0;
	else if(n < 0)
		ans = -INF;
	else
		ans = max(solve(i+1,n),1+solve(i+1,min(n-W[i],L[i])));
	if(n >= 0)
		mem[i][n] = ans;
	return ans;

}



int main(){
	int i,ans,w;
	cin>>N;
	while(N){
		ms(mem,-1);
		ms(W,-1);
		ms(L,-1);
		w = 0;
		for(i = 0 ; i < N;i++){
			cin>>W[i]>>L[i];
			w = max(w,W[i]+L[i]);
		}
		ans = solve(0,w);
		cout<<ans<<endl;
		cin>>N;

	}
	return 0;
}