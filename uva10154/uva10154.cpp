#include <iostream>
#include <string.h>
#include <limits>
#include <limits.h>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define INF INT_MAX
using namespace std;

int W[5700],M[5700],N;

int solve(int i,int r){
	int ans;
	if(i == N)
		ans = 0;
	else{
		ans = solve(i+1,r);
		if(W[i] <= r)
			ans = max(ans,1+solve(i+1,min(r-W[i],M[i]-W[i])));
	}
	return ans;
}


int main(){
	int w,m,i = 0;
	while(cin>>w>>m){
		W[i] = w; M[i] = m;
		i++;
	}
	N = i;
	for(int j = 0; j < i;j++)
		cout<<W[j]<<" "<<M[j]<<endl;
	cout<<solve(0,INF)<<endl;

	return 0;
}