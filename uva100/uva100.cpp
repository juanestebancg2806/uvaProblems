#include <iostream>
using namespace std;

int solve(int n){
	int ans = 1;
	while(n != 1){
		ans += 1;
		if(n%2 == 0)
			n = n/2;
		else
			n = 3*n+1;
	}
	return ans;
}

int main(){
	int i,j,k,l,ans;
	while(cin>>i>>j){
		if (i>j){
			k = j;
			l = i;
		}
		else{
			k = i;
			l = j;
		}
		
		ans = 0;
		for(;k<=l;k++)
			ans = max(ans,solve(k));
		cout<<i<<" "<<j<<" "<<ans<<endl; 


	}
	return 0;
}