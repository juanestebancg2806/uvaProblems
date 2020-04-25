#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;


struct node{
	int u,v,d;
};
typedef struct node node;


vector<int> dforest;
int ccount;

int fi(int x){
	int p = x,ans;
	stack <int> s;
	while(x != dforest[x]){
		s.push(x);
		x = dforest[x];
	}
	ans = x;
	while(!s.empty()){
		dforest[s.top()] = ans;
		s.pop();
	}

	return ans;
}

void un(int x,int y){
	int fx = fi(x),fy = fi(y);
	if(fx != fy){
		dforest[fy] = fx;
		ccount--;
	}

}

bool compare(node n1,node n2){
	return n1.d <= n2.d;
}


int kruskal(int A,int n,vector<node> G){
	int ans = 0,d = -1,uu,vv,dd;
	int i = 0;
	//cout<<"d"<<endl;
	while (i < n and d < A){
		uu = G[i].u,vv = G[i].v,dd = G[i].d;
		//cout<<uu<<" "<<vv<<" "<<dd<<endl;
		if(dd < A && fi(uu) != fi(vv)){
			ans += dd;
			un(uu,vv);
		}

		i += 1;
	}
	ans += ccount*A;
	return ans;
}

int main(){
	int T,N,M,A,x,y,c,i,TC = 1,ans;
	node tmpnode;
	cin>>T;
	while(T--){
		vector<node> G;
		dforest.clear();
		cin>>N>>M>>A;
		ccount = N;
		for(i = 0;i < N;i++) 
			dforest.push_back(i);

		for(i = 0; i < M;i++){
			cin>>x>>y>>c;
			tmpnode.u = x-1,tmpnode.v = y-1,tmpnode.d = c;
			G.push_back(tmpnode);

		}
		//cout<<N<<" "<<M<<" "<<A<<" "<<G.size()<<endl;
		sort(G.begin(),G.end(),compare);
		ans = kruskal(A,M,G);
		cout<<"Case #"<<TC<<": "<<ans<<" "<<ccount<<endl;
		TC++;
	}

	return 0;
}


