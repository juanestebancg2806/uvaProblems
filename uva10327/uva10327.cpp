#include <iostream>
#include <algorithm>
using namespace std;
int arr[10000];
int tmp[10000];


int solve_aux(int low,int mid,int hi){
	int i = low,j = mid,ans = 0,k = 0;
	while(i<mid && j < hi){
		if(arr[i]<=arr[j]){
			tmp[k] = arr[i];
			i++;
		}
		else{
			tmp[k] = arr[j];
			ans += mid-i;
			j++;
		}
		k++;
	}
	while(i < mid){
		tmp[k] = arr[i];
		i++;
		k++;
	}
	while(j < hi){
		tmp[k] = arr[j];
		j++;
		k++;
	}
	k = 0;
	for(i = low; i < hi;i++){
		arr[i] = tmp[k];
		k++;
	}
	return ans;

}

int solve(int low,int hi){
	int ans,mid;
	if (low == hi || low +1 == hi)
		ans = 0;
	else{
		mid = (low+hi)/2;
		ans = solve(low,mid);
		ans += solve(mid,hi);
		ans += solve_aux(low,mid,hi);
	}
	return ans;
}


int main(){
	int n,v,i;
	while(cin>>n){
		for(i = 0; i<n;i++){
			cin>>v;
			arr[i] = v;
		}
		cout<<"Minimum exchange operations : "<<solve(0,n)<<endl;
	}
}