#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
set<string> ss;
string s;


void solve(int N,int K){
	char act = s[N-1];
	if(K == 0)
		ss.insert(s);
	else if(N > 0 && K > 0){
		solve(N-1,K);
		s[N-1] = 'A';
		solve(N-1,K-1);
		s[N-1] = 'C';
		solve(N-1,K-1);
		s[N-1] = 'G';
		solve(N-1,K-1);
		s[N-1] = 'T';
		solve(N-1,K-1);
		s[N-1] = act;

	}
}

int main(){
	int T,N,K,i;
	vector<string> DNAmut;
	cin>>T;
	while(T--){
		ss.clear();
		DNAmut.clear();
		cin>>N>>K;
		cin>>s;
		solve(N,K);
		cout<<ss.size()<<endl;
		for(set<string>::iterator it = ss.begin(); it != ss.end();it++ )
			DNAmut.push_back(*it);
		sort(DNAmut.begin(),DNAmut.end());
		for(i = 0; i < DNAmut.size();i++)
			cout<<DNAmut[i]<<endl;

	}
	return 0;
}