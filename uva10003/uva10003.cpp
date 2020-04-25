#include <iostream>
#include <string.h>
#define ms(a,b) memset(a,b,sizeof(b))
#define INF 99999999
using namespace std;

int cuts[51];
int mem[51][1000];
int N;

int solve(int i,int n){
	int ans;
	//if(mem[i][n] != -1)
	//	ans = mem[i][n];
	if(n == 0)
		ans = 0;
	else if((i == N && n != 0) || n < 0)
		ans = INF;
	else{
		/*ans = INF;
		if (cuts[i] <= n)
			ans = n + solve(i,n-cuts[i]);
		ans = min(ans,solve(i+1,n));
		*/
		ans = min(solve(i+1,n),n+solve(i,n-cuts[i]));

	}
	return ans;
}
int main(){
	int l,i;
	cin>>l;
	while(l != 0){
		ms(mem,-1);
		cin>>N;
		for(i = 0; i < N;i++)
			cin>>cuts[i];
		cout<<solve(0,l)<<endl;
		cin>>l;
	}
	return 0;
}