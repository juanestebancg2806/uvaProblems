#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))

using namespace std;

vector<vector<int> > garments;
int mem[205][22],INF = 1000000;


int solve(int M,int C){
	int ans,i;
	if(mem[M][C] != -1){
		ans = mem[M][C];
	}
	else if(M == 0 && C != 0)
		ans = -INF;
	else if(C == 0)
		ans = 0;
	else{
		ans = -INF;
		for(i = 0; i < garments[C-1].size();i++){
			if(garments[C-1][i] <= M)
				ans = max(ans,garments[C-1][i]+solve(M-garments[C-1][i],C-1));
		}
	}
	return mem[M][C] = ans;
}


int main(){
	int N,M,C,K,c,i,j,ans;
	vector<int> tmp;
	cin>>N;
	while(N--){
		cin>>M>>C;
		garments.clear();
		ms(mem,-1);
		for(i = 0; i < C;i++){
			cin>>K;
			garments.push_back(tmp);
			for(j = 0; j < K;j++){
				cin>>c;
				garments[garments.size()-1].push_back(c);
			}
		}
		ans = solve(M,C);
		if(ans > 0)
			cout<<ans<<endl;
		else
			cout<<"no solution"<<endl;

	}
	return 0;
}