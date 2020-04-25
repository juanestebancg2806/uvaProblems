#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
unsigned long long int arr[10000000];

bool tryk(unsigned long long int k,int v){
	int i = 1;
	bool ans = true;
	if (k < arr[0])
		ans = false;
	if (k == arr[0])
		k--;
	while(i < v && ans){
		if(arr[i] - arr[i-1] == k)
			k--;
		else if(arr[i]-arr[i-1] > k)
			ans = false;
		i++;
	}
	return ans;
}	

int solve(int v){
	unsigned long long int low = 0,hi = 10000000,ans = -1,mid;
	while(low+1 != hi){
		mid = (low+hi)/2;
		if (tryk(mid,v)){
			ans = mid;
			hi = mid;
		}
		else{
			low = mid;
		}
	}
	return ans;

}

int main(){
	int n,v,i,k,TC = 1;
	cin>>n;
	while(n--){
		cin>>v;
		for(i = 0; i < v;i++){
			cin>>k;
			arr[i] = k;
		}
		cout<<"Case "<<TC<<": "<<solve(v)<<endl;
		TC++;

	}
	return 0;
}