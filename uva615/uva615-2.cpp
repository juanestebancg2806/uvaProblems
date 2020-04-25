#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <map>
using namespace std;

bool iskey(map<int,int> index,int u){
	bool ans = false;
	for(map<int,int>::iterator it = index.begin(); it != index.end() && !ans;it++){
		if(it->first == u)
			ans = true;
	}
	return ans;

}

bool solve(vector<vector<int> > G){
		int i,j,root = -1,tmp = -1,n = G.size();
		vector<int> indeg(n,0);
		vector<bool> visited(n,false);
		stack<int> s;
		bool ans = true;
		for(i = 0; i < n && ans; i++){
			for(j = 0; j < G[i].size();j++){
				indeg[G[i][j]] += 1;
			}
		}
		//for(i = 0; i < n;i++)
		//	cout<<indeg[i] <<" ";
		j = 0;
		for(i = 0; i < n && ans;i++){
			if (indeg[i] == 0){
				root = i;
				j++;
			}
			ans = j <= 1 && indeg[i] <= 1;
		}
		if( root != -1){
			s.push(root);
			visited[root] = true;
			
		}
		while(!s.empty() && ans){
			tmp = s.top();s.pop();
			for(i = 0; i < G[tmp].size() && ans; i++){
				if(!visited[G[tmp][i]]){
					visited[G[tmp][i]] = true;
					s.push(G[tmp][i]);
				}
				else
					ans = false;
			}

		}
		for(i = 0; i < n && ans; i++){
			ans = ans && visited[i];
		}
		return ans;	


}


int main(){
	int u,v,i,j,tc = 1;
	bool ans;
	cin>>u>>v;
	while(u >= 0 && v >= 0){
		vector<int> edges;
		i = 0;
		map<int,int> index;
		map<int,int> r;
		//edges.push_back(u,v);
		while(u != 0 && v != 0){
			edges.push_back(u);
			edges.push_back(v);
			cin>>u>>v;
		}
		//for(j = 0; j < edges.size();j++)
		//	cout<<edges[j]<<" ";
		//cout<<endl;
		i = 0;
		for(j = 0; j < edges.size();j++){
			if(!iskey(index,edges[j])){
				index[edges[j]] = i;
				r[i] = edges[j];
				i += 1;
			}
		}
		vector<int> tmp;
		vector<vector<int> > G;
		for(j = 0; j < i;j++)
			G.push_back(tmp);

		for(j = 0; j < edges.size(); j+=2){
			u = index[edges[j]];
			v = index[edges[j+1]];
			//cout<<u<<" "<<v<<endl;
			if (u != v);
				G[u].push_back(v);
		}
		//for(map<int,int>::iterator it = index.begin();it != index.end();it++)
	//		cout<<r[it->first]<<" "<<r[it->second]<<endl;

		ans = solve(G);
		if(ans)
			cout<<"Case "<<tc<<" is a tree."<<endl;
		else
			cout<<"Case "<<tc<<" is not a tree."<<endl;
		tc++;
		cin>>u>>v;


	}
	return 0;
}