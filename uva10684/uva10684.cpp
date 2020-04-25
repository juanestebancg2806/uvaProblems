#include <iostream>
#include <algorithm>

using namespace std;

int array[10001];



int solve_aux(int low,int mid,int hi){
	int i = mid,j = mid+1,left = 0,right = 0,tmp = 0;
	while(i >= 0){
		tmp += array[i];
		left = max(left,tmp);
		i -= 1;
	}
	tmp = 0;
	while(j < hi){
		tmp += array[j];
		right = max(right,tmp);
		j += 1;
	}
	return right+left;
}

int solve(int low,int hi){
	int ans,mid,left,right,medium;
	if (low >= hi)
		ans = 0;
	else if(low +1 == hi)
		ans = array[low];
	else{
		mid = (low+hi)/2;
		left = solve(low,mid);
		right = solve(mid,hi);
		medium = solve_aux(low,mid,hi);
		ans = max(max(left,right),medium);
	}
	return ans;

}

int main(){
	int n,v,i,ans;
	cin>>n;
	while(n){
		for(i = 0; i < n; i++){
			cin>>v;
			array[i] = v;
		}
		ans = solve(0,n);
		if (ans <= 0)
			cout << "Losing streak."<<endl;
		else
			cout<<"The maximum winning streak is "<<ans<<"."<<endl;
		cin>>n;
	}
	return 0;

}
