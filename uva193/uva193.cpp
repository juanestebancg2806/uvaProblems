#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define pb(b) push_back(b)
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;

int colors[100]; 

int n;

vector<vector<int> > G;
vector<vector<int> > parents;
vector<int> ans;
vector<int> path;

void solve(int N){
	int i,j;
	bool ok = true;
	if(N == n)
		ans = path.size() > ans.size() ? path : ans;
	else{
		
		for(i = 0; i < G.size() && ok;i++){
			for(j = 0; j < G[i].size() && ok;j++)
				ok = !(colors[i] == 1 && G[i][j] == N);
			
		}
		
		if(ok){
			colors[N] = 1; path.pb(N+1);
			solve(N+1);
			path.pop_back();
		}
		colors[N] = 2;
		solve(N+1);
		colors[N] = 0;

	}
}


int main(){
	int m,k,i,u,v,j;
	vector<int> nodes;
	ms(colors,0);
	cin>>m;
	while(m--){
		cin>>n>>k;
		ans.clear();path.clear();
		G.clear(); 
		for(i = 0; i < n;i++){
		 G.pb(nodes);
		 parents.pb(nodes);
		}
		for(i = 0; i < k;i++){
			cin>>u>>v;
			G[u-1].pb(v-1);
			G[v-1].pb(u-1);
		}
		solve(0);
		cout<<ans.size()<<endl;
		for(i = 0; i <ans.size();i++){
			if(i+1 == ans.size())
				cout<<ans[i]<<endl;
			else
				cout<<ans[i]<< " ";
		}
			
	}
	return 0;
}