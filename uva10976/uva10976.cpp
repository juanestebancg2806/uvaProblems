#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

class tup{
	public:
		int x,y;
};
vector<tup> ans;

int findX(int k,int _y){
	return (k*_y)/(_y-k);
}

void solve(int k){
	int _x,_y;
	bool ok = true;
	tup t;
	for(_y = k+1; ok;_y++ ){
		_x = (int)findX(k,_y);
		ok = _x >= _y;
		t.x = _x;t.y = _y;
		if(ok && (_x*_y) == k*(_x+_y))
			ans.push_back(t);
	}
}

int main(){
	int k,i;
	while(cin>>k){
		solve(k);
		cout<<ans.size()<<endl;
		for(i = 0; i < ans.size();i++)
			cout<<"1/"<<k<<" = "<<"1/"<<ans[i].x<<" + "<<"1/"<<ans[i].y<<endl;
		ans.clear();
	}
	return 0;
}