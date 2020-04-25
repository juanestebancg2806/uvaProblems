#include <iostream>
#include <string.h>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;

int T1[101],T2[101];


int solve(int r,int n1,int n2){
	int ans;
	if(n1 == 0 && n2 == 0)
		ans = 0;
	else if(n1 != 0 && n2 == 0){
		ans = 0;
		if(T1[n1-1] == r)
			ans = 1+solve(T1[n1-1],n1-1,n2);
		ans = max(ans,solve(r,n1-1,n2));
	}

	else if(n1 == 0 && n2 != 0){
		ans = 0;
		if(T2[n2-1] == r)
			ans = 1+solve(T2[n2-1],n1,n2-1);
		ans = max(ans,solve(r,n1,n2-1));
	}

	else{
		if(r == 0)
			ans = max(1+solve(T1[n1-1],n1-1,n2),1+solve(T2[n2-1],n1,n2-1));
		else{
			ans = 0;
			if(T1[n1-1] == r)
				ans = max(ans,1+solve(T1[n1-1],n1-1,n2));
			if(T2[n2-1] == r)
				ans = max(ans,1+solve(T2[n2-1],n1,n2-1));
			ans = max(ans,solve(r,n1-1,n2));
			ans = max(ans,solve(r,n1,n2-1));
		}
	}

	return ans;
}

int main(){
	int i,ans,N1,N2,TC = 1;
	cin>>N1>>N2;
	while(!(N1 == 0 && N2 == 0)){
		ms(T1,0);ms(T2,0);
		for(i = 0; i < N1;i++)
			cin>>T1[i];
		for(i = 0; i < N2;i++)
			cin>>T2[i];
		ans = solve(0,N1,N2);
		cout<<"Twin Towers #"<<TC<<"\n"<<"Number of Tiles : "<<ans<<endl;
		TC++;
		cin>>N1>>N2;

	}
	return 0;
}