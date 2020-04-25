#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define pb(b) push_back(b)

using namespace std;

int visited[26][26];
vector<vector<int> > G;

int dfs(int u){
	int ans = 0,i,v;
	visited[u][u] = 1;
	for(i = 0;i < G[u].size();i++){
		v = G[u][i];
		if(visited[u][v] == 0){
			visited[u][v] = visited[v][u] = 1;
			ans = max(ans,1+dfs(v));
			visited[u][v] = visited[v][u] = 0;
		}
	}
	visited[u][u] = 0;
	return ans;
}

int solve(){
	int ans = 0,i = 0;
	for(i = 0; i < G.size();i++)
		ans = max(ans,dfs(i));
	return ans;
}


int main(){
	int n,m,u,v,i;
	vector<int> tmp;
	cin>>n>>m;
	while(!(n == 0 && m == 0)){
		G.clear();
		ms(visited,0);
		for(i = 0; i < n;i++)
			G.pb(tmp);
		for(i = 0; i < m;i++){
			cin>>u>>v;
			G[u].pb(v);
			G[v].pb(u);
		}
		cout<<solve()<<endl;
		cin>>n>>m;

	}
	return 0;
}