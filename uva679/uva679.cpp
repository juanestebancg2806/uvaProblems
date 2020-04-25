#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>  
using namespace std;


int solve(unsigned long long int n,int I){
	unsigned long long int i = 0,ans = 1;
	while(i+1 < n){
		ans = i+1;
		if(I%2 == 0){
			i = (2*i)+2;
			I /=2;
		}
		else{
			i = (2*i)+1;
			I = (I/2) +1;
		}

	}
	return ans;
}


int main(){
	int tc,D,I,i;
	unsigned long long int n,ans;
	cin>>tc;
	for(i = 0; i< tc; i++){
		cin>>D>>I;
		n = pow(2,D);//the depth of the tree
		ans = solve(n,I);
		cout<<ans<<endl;
	}
	cin>>i;
	return 0;
}