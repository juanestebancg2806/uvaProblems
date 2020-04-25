#include <iostream>
#include <limits.h>
#include <string.h>
#include <vector>
#define ms(a,b) memset(a,b,sizeof(a))
#define INF INT_MAX
using namespace std;
vector<int> numbers,path,ans;
bool f;


int sum(vector<int> v){
	int ansS = 0;
	for(vector<int>::iterator it = v.begin(); it != v.end();it++)
		ansS += *it;
	return ansS;
}

void solve(int i,int n){
	int s1,s2;
	if(!f){
		f = f || n == 0;
		if(n == 0)
			ans = path;
		else if(i == numbers.size() && !f){
			s1 = sum(path),s2 = sum(ans);
			ans = (s1>s2) ? path: ans;
		}
		else{
			if(numbers[i]<=n){
				path.push_back(numbers[i]);
				solve(i+1,n-numbers[i]);
				path.pop_back();
			}

			solve(i+1,n);
		}

	}
}


int main(){
	int tracks,v,N,s,i;
	while(cin>>N){
		f = false;s = 0;
		numbers.clear();path.clear();ans.clear();
		cin>>tracks;
		while(tracks--){
			cin>>v;
			numbers.push_back(v);
		}
		solve(0,N);
		for(i = 0; i < ans.size();i++){
			s += ans[i];
			cout<<ans[i]<<" ";
		}
		cout<<"sum:"<<s<<endl;

	}
	return 0;
}

