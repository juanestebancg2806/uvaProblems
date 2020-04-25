#include <iostream>
#include <string.h>
#include <vector>
#include <tuple>
#include <math.h>
#include <algorithm>
#define ms(a,b) memset(a,b,sizeof(a))
#define pb(b) push_back(b)
using namespace std;

int visited[10],n;
vector<int> path;
vector<vector<tuple<int,int> > > G;

int getDistance(int u,int v,vector<int> vec){
	int lo,hi,i;
	for(i = 0; i < vec.size();i++){
		if(vec[i] == u)
			lo = i;
		else if(vec[i] == v)
			hi = i;
	}
	return abs(hi-lo);
}

int solve(int N){
	int ans,i,j,d;
	tuple<int,int> t;
	if(N == n){
		ans = 1;
		for(i = 0; i < G.size() && ans;i++){
			for(j = 0; j < G[i].size() && ans;j++){
				t = G[i][j];
				d = getDistance(i,get<0>(t),path);
				if(get<1>(t) < 0 && d < abs(get<1>(t)))
					ans = 0;
				else if(get<1>(t) > 0 && d > abs(get<1>(t)))
					ans = 0;
			}
		}
	}
	else{
		ans = 0;
		for(i = 0; i < n;i++){
			if(visited[i] == -1){
				path.pb(i);
				visited[i] = 1;
				ans += solve(N+1);
				visited[i] = -1;
				path.pop_back();
			}
		}

	}
	return ans;
}



int main(){
	int m,i,a,b,c;
	cin>>n>>m;
	vector<tuple<int,int> > tmp;
	tuple<int,int> t;
	while(!(n == 0 && m == 0)){
		ms(visited,-1);
		for(i = 0; i < n;i++)
			G.pb(tmp);
		for(i = 0; i < m;i++){
			cin>>a>>b>>c;
			t = make_tuple(b,c);
			G[a].pb(t);
		}
		cout<<solve(0)<<endl;
		G.clear();
		cin>>n>>m;


	}

	return 0;

}