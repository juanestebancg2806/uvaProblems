#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class car{
	public:
		string name;
		int l,h;
};

vector<car> cars;
bool compare(car c1,car c2){
	return c1.l <= c2.l;
}

string search(int x){
	int i,cnt = 0;
	string ans = "UNDETERMINED";
	for(i = 0; i < cars.size() && cars[i].l <= x && cnt <= 1;i++){
		if(cars[i].l <= x && x <= cars[i].h){
			ans = cars[i].name;
			cnt++;
		}
	}
	if(cnt > 1)
		ans = "UNDETERMINED";
	return ans;
}


int main(){
	int TC,D,L,H,Q,P,i;
	string s;
	car c;
	cin>>TC;
	while(TC--){
		cars.clear();
		cin>>D;
		for(i = 0; i < D;i++){
			cin>>s>>L>>H;
			c.name = s; c.l = L; c.h = H;
			cars.push_back(c);
		}
		sort(cars.begin(),cars.end(),compare);
		cin>>Q;
		for(i = 0; i < Q;i++){
			cin>>P;
			cout<<search(P)<<endl;
		}
		if(TC-1 >= 0){
			cout<<endl;
		}
	}
	return 0;
}