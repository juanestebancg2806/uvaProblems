#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class e{
	public:
		int w,iq,idx;
};

bool cmp(const e& x,const e& y){
		return x.iq > y.iq;
}

vector<e> inp;

void solve(){
	int N = inp.size(),i,j,maxv = 1,maxi = 0;
	vector<vector<int> > path(N);
	path[0].push_back(inp[0].idx);
	for(i = 1; i < N; i++){
		for(j = 0; j < i;j++){
			if(inp[j].w < inp[i].w && inp[j].iq > inp[i].iq && path[i].size() < path[j].size()+1)
				path[i] = path[j];
		}
		path[i].push_back(inp[i].idx);
		if(path[i].size() > maxv){
			maxv = path[i].size();
			maxi = i;
		}

	}
	cout<<path[maxi].size()<<endl;
	for(i = 0; i < path[maxi].size();i++)
		cout<<path[maxi][i]<<endl;

}

int main(){
	int w,iq,i = 1;
	e tmp;
	while(cin>>w>>iq){
		tmp.w = w;
		tmp.iq = iq;
		tmp.idx = i;
		inp.push_back(tmp);
		i += 1;
	}
	sort(inp.begin(),inp.end(),cmp);
	solve();

	return 0;
}
